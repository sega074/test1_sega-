/*
 ============================================================================
 Name        : v1.c
 Author      : sega
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


/*
 *  m[] - массив не убывающих целых чисел
 *  le - длинна массива
 *  x -целая величина для поиска элементра массива в строгости больше заданной величины
 *  при успешном поиске возвращает индекс по условию при ощибочном возвращает количество
 *  элементов в массиве
 */

int bsea(int m[], int le, int x){
	int il ,ih, id;
	il = 0;
	ih = le -1;
	id = ih;			// разница между минимальным и максимальным значеним индекса

	while (id >0 && il < ih){
		if (x < m [il + id]){
			ih = il +id;
		} else {
			il+=id;
		}
		id = id >> 1;
	}

	for (id = il; id <=ih; id++){
		if (x < m[id])
		return id;
	}

	return le;
}
int main(void) {
	int ms[100];
	int r;
	int i=0;
	for (i= 0 ; i < 100 ; i++){
		if (i > 20 && i <30){
			ms[i] = 22;
		} else {
		ms[i] = i + 2;
		}
	}

	for (i =0 ; i <100; i++){
		printf ("ms[%i] = %i \n", i , ms[i]);
	}

	for ( i = 110 ; i >0 ; i-- ){
		r = bsea(ms,100,i);
		if (r == 100){
			printf("для %i значение индека  по условию не найдено\n", i);
			continue;
		}
		printf( "поиск для значения =  %i   нашли индекс =  %i со значениеем %i \n", i, r, ms[r]);
	}



	return EXIT_SUCCESS;
}

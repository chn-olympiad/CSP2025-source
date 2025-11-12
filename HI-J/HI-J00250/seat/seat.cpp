#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

uint32_t n, m, *scores = NULL, cscore = 0, seat = 0;
bool flag = false;

int32_t CompareForQSortReverse32U(const void *ptr1, const void *ptr2)
{
	uint32_t *pNum1 = (uint32_t*)ptr1;
	uint32_t *pNum2 = (uint32_t*)ptr2;
	return -((int32_t)*pNum1 - (int32_t)*pNum2);
}

uint32_t GetSeatLine(uint32_t nCols, uint32_t nLines, uint32_t nSeat)
{
	uint32_t nLine = nSeat % nLines;
	uint32_t nCol = nSeat / nLines;
	if (nCol % 2 != 0)
		return nLines - nLine;
	return nLine + 1;
}

int main(void)
{
	scanf("%u%u", &n, &m);
	if (!n || !m || n > 10 || m > 10)
		abort();
	scores = (uint32_t*)calloc(n * m + 1, sizeof(uint32_t));
	if (!scores)
		abort();
	for (uint32_t i = 0; i < n * m; i++)
	{
		scanf("%u", scores + i);
		if (*(scores + i) > 100)
			abort();
		if (!flag)
		{
			cscore = *(scores + i);
			flag = true;
		}
	}
	qsort(scores, n * m, sizeof(uint32_t), CompareForQSortReverse32U);
	while (*(scores + seat) != cscore)
		++seat;
	printf("%u %u\n", seat / n + 1, GetSeatLine(m, n, seat));
	free(scores);
	return 0;
}

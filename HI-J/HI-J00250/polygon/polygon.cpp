#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

uint32_t n = 0, *l = NULL, *l2 = NULL;
uint64_t ans = 0;

uint64_t SumUp32U64U(const uint32_t *pArray, size_t cArray)
{
	uint64_t nSum = 0;
	for (size_t i = 0; i < cArray; i++)
		nSum += *(pArray + i);
	return nSum;
}

uint32_t ArrayMax32U(const uint32_t *pArray, size_t cArray)
{
	uint32_t nMax = 0;
	for (size_t i = 0; i < cArray; i++)
	{
		if (*(pArray + i) > nMax)
			nMax = *(pArray + i);
	}
	return nMax;
}

int main(void)
{
	scanf("%u", &n);
	if (n < 3 || n > 5000)
		abort();
	l = (uint32_t*)calloc(n + 1, sizeof(uint32_t));
	if (!l)
		abort();
	l2 = (uint32_t*)calloc(n + 1, sizeof(uint32_t));
	if (!l2)
		abort();
	for (uint32_t i = 0; i < n; i++)
	{
		scanf("%u", l + i);
		if (*(l + i) > 5000)
			abort();
	}
	if (SumUp32U64U(l, n) > 2 * (uint64_t)ArrayMax32U(l, n))
		++ans;
	printf("%llu\n", ans);
	free(l2);
	free(l);
	return 0;
}

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

uint32_t n = 0, k = 0, *a = NULL, ans = 0;

int main(void)
{
	scanf("%u%u", &n, &k);
	if (!n || n > (uint64_t)5e5 || k >= 1048576)
		abort();
	a = (uint32_t*)calloc(n, sizeof(uint32_t));
	if (!a)
		abort();
	for (uint32_t i = 0; i < n; i++)
	{
		scanf("%u", a + i);
		if (*(a + i) >= 1048576)
			abort();
	}
	for (uint32_t i = 0; i < n; i++)
	{
		if (*(a + i) == k)
			++ans;
		else
		{
			uint32_t tmp = *(a + i);
			uint32_t jmpto = i;
			for (uint32_t j = i + 1; j < n; j++)
			{
				tmp ^= *(a + j);
				if (tmp == k)
				{
					++ans;
					jmpto = j;
					break;
				}
			}
			i = jmpto;
		}
	}
	printf("%u\n", ans);
	free(a);
	return 0;
}

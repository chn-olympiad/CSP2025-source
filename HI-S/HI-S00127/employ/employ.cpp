#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <memory.h>

uint32_t n, m;
char *s = NULL;
uint32_t *c = NULL;
uint64_t ans = 0;

void __Swap(void *ptr1, void *ptr2, size_t cbSwap)
{
	if (!ptr1 || !ptr2 || !cbSwap)
		return;
	uint8_t *cptr1 = (uint8_t*)ptr1;
	uint8_t *cptr2 = (uint8_t*)ptr2;
	for (size_t i = 0; i < cbSwap; i++)
	{
		uint8_t ctmp = *(cptr1 + i);
		*(cptr1 + i) = *(cptr2 + i);
		*(cptr2 + i) = ctmp;
	}
}

int main(void)
{
	scanf("%u%u", &n, &m);
	if (!n || !m || m > n)
		abort();
	s = (char*)calloc(n + 1, sizeof(char));
	if (!s)
		abort();
	c = (uint32_t*)calloc(n, sizeof(uint32_t));
	if (!c)
		abort();
	scanf("%s", s);
	for (uint32_t i = 0; i < n; i++)
	{
		scanf("%u", c + i);
	}
	for (uint32_t i = 0; i < n; i++)
	{
		for (uint32_t j = 0; j < n - 1; j++)
		{
			__Swap(c + (n - 2 - j), c + (n - 1 - j), sizeof(uint32_t));
			uint32_t failed = 0;
			uint32_t succeed = 0;
			for (uint32_t k = 0; k < n; k++)
			{
				if (s[k] == '0' || c[k] <= failed)
					++failed;
				else
					++succeed;
			}
			if (succeed >= m)
				++ans;
		}
	}
	printf("%u\n", (uint32_t)(ans % 998244353));
	free(s);
	free(c);
	return 0;
}

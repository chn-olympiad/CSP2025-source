#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct tagCITY
{
	uint32_t u;
	uint32_t v;
	uint32_t w;
} CITY, *PCITY;

uint32_t n, m, k;
uint32_t *c = NULL, **a = NULL;
PCITY pct = NULL;

int main(void)
{
	scanf("%u%u%u", &n, &m, &k);
	if (!n || !m)
		abort();
	pct = (PCITY)calloc(m, sizeof(CITY));
	if (!pct)
		abort();
	c = (uint32_t*)calloc(k, sizeof(uint32_t));
	if (!c)
		abort();
	a = (uint32_t**)calloc(k, sizeof(uint32_t*));
	if (!a)
		abort();
	for (uint32_t i = 0; i < k; i++)
	{
		a[i] = (uint32_t*)calloc(n, sizeof(uint32_t));
		if (!a[i])
			abort();
	}
	for (uint32_t i = 0; i < m; i++)
	{
		scanf("%u%u%u", pct[i].u, pct[i].v, pct[i].w);
	}
	for (uint32_t i = 0; i < k; i++)
	{
		scanf("%u", c[i]);
		for (uint32_t j = 0; j < n; j++)
		{
			scanf("%u", a[j]);
		}
	}
	free(pct);
	free(c);
	for (uint32_t i = 0; i < k; i++)
		free(a[i]);
	free(a);
	return 0;
}

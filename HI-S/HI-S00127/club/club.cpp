#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct tagCLUBSCORE
{
	uint32_t nScore1;
	uint32_t nScore2;
	uint32_t nScore3;
} CLUBSCORE, *PCLUBSCORE;

typedef struct tagSCOREANALYZIS
{
	uint32_t nScore;
	uint32_t nBoddy1;
	uint32_t nBoddy2;
	uint32_t nBoddy3;
} SCOREANALYZIS, *PSCOREANALYZIS;

int32_t CompareScore(const void *ptr1, const void *ptr2)
{
	PCLUBSCORE pcs1 = (PCLUBSCORE)ptr1;
	PCLUBSCORE pcs2 = (PCLUBSCORE)ptr2;
	return -((int32_t)(pcs1->nScore1 + pcs1->nScore2 + pcs1->nScore3) - (int32_t)(pcs2->nScore1 + pcs2->nScore2 + pcs2->nScore3));
}

uint32_t t = 0, n = 0;
PCLUBSCORE pcs = NULL;
SCOREANALYZIS sa;

int main(void)
{
	scanf("%u", &t);
	if (!t)
		abort();
	for (uint32_t i = 0; i < t; i++)
	{
		memset(&sa, 0, sizeof(sa));
		scanf("%u", &n);
		if (!n || n > (uint32_t)1e5)
			abort();
		pcs = (PCLUBSCORE)calloc(n, sizeof(CLUBSCORE));
		if (!pcs)
			abort();
		for (uint32_t j = 0; j < n; j++)
		{
			scanf("%u%u%u", &(pcs + j)->nScore1, &(pcs + j)->nScore2, &(pcs + j)->nScore3);
			if ((pcs + j)->nScore1 > (uint32_t)(2 * 1e4) || (pcs + j)->nScore2 > (uint32_t)(2 * 1e4) || (pcs + j)->nScore3 > (uint32_t)(2 * 1e4))
				abort();
		}
		qsort(pcs, n, sizeof(CLUBSCORE), CompareScore);
		for (uint32_t j = 0; j < n; j++)
		{
			uint32_t sctmp = max((pcs + j)->nScore1, max((pcs + j)->nScore2, (pcs + j)->nScore3));
			if (sctmp == (pcs + j)->nScore1)
			{
				if (sa.nBoddy1 < n / 2)
					++sa.nBoddy1;
				else
				{
					sctmp = max((pcs + j)->nScore2, (pcs + j)->nScore3);
					if (sctmp == (pcs + j)->nScore2)
					{
						if (sa.nBoddy2 < n / 2)
							++sa.nBoddy2;
						else
						{
							sctmp = (pcs + j)->nScore3;
							++sa.nBoddy3;
						}
					}
					else if (sctmp == (pcs + j)->nScore3)
					{
						if (sa.nBoddy3 < n / 2)
							++sa.nBoddy3;
						else
						{
							sctmp = (pcs + j)->nScore2;
							++sa.nBoddy2;
						}
					}
				}
			}
			else if (sctmp == (pcs + j)->nScore2)
			{
				if (sa.nBoddy2 < n / 2)
					++sa.nBoddy2;
				else
				{
					sctmp = max((pcs + j)->nScore1, (pcs + j)->nScore3);
					if (sctmp == (pcs + j)->nScore1)
					{
						if (sa.nBoddy1 < n / 2)
							++sa.nBoddy1;
						else
						{
							sctmp = (pcs + j)->nScore3;
							++sa.nBoddy3;
						}
					}
					else if (sctmp == (pcs + j)->nScore3)
					{
						if (sa.nBoddy3 < n / 2)
							++sa.nBoddy3;
						else
						{
							sctmp = (pcs + j)->nScore1;
							++sa.nBoddy1;
						}
					}
				}
			}
			else if (sctmp == (pcs + j)->nScore3)
			{
				if (sa.nBoddy3 < n / 2)
					++sa.nBoddy3;
				else
				{
					sctmp = max((pcs + j)->nScore1, (pcs + j)->nScore2);
					if (sctmp == (pcs + j)->nScore1)
					{
						if (sa.nBoddy1 < n / 2)
							++sa.nBoddy1;
						else
						{
							sctmp = (pcs + j)->nScore2;
							++sa.nBoddy2;
						}
					}
					else if (sctmp == (pcs + j)->nScore2)
					{
						if (sa.nBoddy2 < n / 2)
							++sa.nBoddy2;
						else
						{
							sctmp = (pcs + j)->nScore1;
							++sa.nBoddy1;
						}
					}
				}
			}
			sa.nScore += sctmp;			
		}
		printf("%u\n", sa.nScore);
		free(pcs);
		pcs = NULL; 
	}
	return 0;
}

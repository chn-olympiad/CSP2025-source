#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char s[1000001];

int32_t CompareForQSortReverse8(const void *ptr1, const void *ptr2)
{
	char *chr1 = (char*)ptr1;
	char *chr2 = (char*)ptr2;
	return -((int32_t)*chr1 - (int32_t)*chr2);
}

size_t PrintLoop(const char *pStr, char chMin, char chMax, const char *pEndStr)
{
	if (!pStr || chMin > chMax)
		return 0;
	char *pStr2 = (char*)pStr;
	size_t count = 0;
	while (*pStr2 != '\0')
	{
		if (*pStr2 >= chMin && *pStr2 <= chMax)
		{
			fputc(*pStr2, stdout);
			++count;
		}
		++pStr2;
	}
	fputs(pEndStr ? pEndStr : "\n", stdout);
	return count;
}

int main(void)
{
	scanf("%s", s);
	if (s[1000000] != '\0')
		abort();
	qsort(s, strlen(s), sizeof(char), CompareForQSortReverse8);
	PrintLoop(s, '0', '9', "\n");
	return 0;
}

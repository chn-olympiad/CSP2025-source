#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <memory.h>

#include <iostream>
#include <string>

uint32_t n, q, ans = 0;
std::string s1[200001], s2[200001];
std::string t1[200001], t2[200001];

int main(void)
{
	scanf("%u%u", &n, &q);
	if (!n || !q)
		abort();
	for (uint32_t i = 0; i < n; i++)
	{
		std::cin >> s1[i] >> s2[i];
	}
	for (uint32_t i = 0; i < q; i++)
	{
		ans = 0;
		std::cin >> t1[i] >> t2[i];
		for (uint32_t j = 0; j < n; j++)
		{
			if (t1[i] == s1[j] && t2[i] == s2[j])
				++ans;
			else
			{
				size_t pos1 = t1[i].find(s1[j], 0);
				size_t pos2 = t2[i].find(s2[j], 0);
				if (pos1 == pos2 && pos1 != (size_t)(uint32_t)-1 && pos2 != (size_t)(uint32_t)-1 && pos1 != (size_t)-1 && pos2 != (size_t)-1)
				{
					if (!strncmp(t1[i].c_str(), t2[i].c_str(), pos1) && !strcmp(t1[i].c_str() + pos1 + s1[j].length(), t2[i].c_str() + pos2 + s2[j].length()))
						++ans;
				}
			}
		}
		printf("%u\n", ans);
	}
	return 0;
}

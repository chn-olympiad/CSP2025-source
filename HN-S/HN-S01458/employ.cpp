#include <algorithm>
#include <iostream>
#include <cstdio>
#include <array>
#include <cstring>

namespace Fujiwara
{
int n, m;
char s[505];
int p[505], c[505];
static int Azusa()
{
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", c + i);
		p[i] = i;
	}
	int res = 0;
	do
	{
		int cnt = 0, pre = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (pre >= c[p[i]] || s[i] == '0')
				++pre;
			else
				++cnt;
		}
		if (cnt >= m)
			++res;
	} while(std::next_permutation(p + 1, p + n + 1));
	printf("%d\n", res);
	return 0;
}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	return Fujiwara::Azusa();
}
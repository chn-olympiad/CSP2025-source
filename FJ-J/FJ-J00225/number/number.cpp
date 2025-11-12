#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
char s[MAXN], s0[MAXN];

bool cmp(char a, char b)
{
	return a > b;
}

int main()
{
	freopen("number.in", "r", stdin); freopen("number.out", "w", stdout);
	scanf("%s", &s);
	int len = strlen(s), ls = 0;
	for (int rp = 0; rp < len; rp ++)
	{
		if (s[rp] >= '0' && s[rp] <= '9')
			s0[ls ++] = s[rp];
	}
	sort(s0, s0 + ls, cmp);
	printf("%s", s0);
	printf("\n");
	return 0;
}


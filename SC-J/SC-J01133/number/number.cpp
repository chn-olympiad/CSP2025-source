#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

char s[N];
int tmp[N];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	int n = strlen(s + 1), cur = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			tmp[++cur] = s[i] - '0';
	}
	sort(tmp + 1, tmp + cur + 1, cmp);
	for (int i = 1; i <= cur; i++)
		putchar((char)(tmp[i] + '0'));
	return 0;
}

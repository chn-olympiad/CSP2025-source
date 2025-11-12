#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;
int a[MAXN * MAXN];

bool cmp(char a, char b)
{
	return a > b;
}

int main()
{
	freopen("seat__.in", "r", stdin); freopen("seat__.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	int nm = n * m;
	for (int i = 1; i <= nm; ++ i)
		scanf("%d", &a[i]);
	int sc = a[1];
	sort(a + 1, a + nm + 1, cmp);
	int cnt = 1, i = 1, j = 1;
	while (cnt <= nm)
	{
//		printf("_debug_%d %d\n", i, j);
		if (a[cnt] == sc)
		{
			printf("%d %d\n", i, j);
			break;
		}
		if (j == 1)
		{
			if (i & 1)
				++ j;
			else
				++ i;
		}
		else if (j == n)
		{
			if (i & 1)
				++ i;
			else
				-- j;
		}
		else
		{
			if (i & 1)
				++ j;
			else
				-- j;
		}
		++ cnt;
	}
	return 0;
}


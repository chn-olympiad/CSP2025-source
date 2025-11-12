#include <bits/stdc++.h>
using namespace std;

int d[110], n, m, q, cnt;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &d[++cnt]);
		}
	}
	q = d[1];
	sort(d + 1, d + 1 + cnt, greater<int>());
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (d[i * n + j] == q)
			{
				printf("%d %d", (i + 1), ((i & 1)? (n - j + 1) : j));
				return 0;
			}
		}
	}
	return 0;
}

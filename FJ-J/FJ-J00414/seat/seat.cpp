#include <bits/stdc++.h>
const int N = 105;

int n, m, a[N], x, num[N][N], cnt;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; ++i) scanf("%d", a + i);
	x = a[1];
	std::sort(a + 1, a + 1 + n * m, std::greater<int>());
	for (int i = 1; i <= n * m; ++i) if (a[i] == x) { x = i; break; }
	for (int j = 1; j <= m; ++j) 
		if (j & 1) for (int i = 1; i <= n; ++i) num[i][j] = ++cnt;
		else for (int i = n; i >= 1; --i) num[i][j] = ++cnt;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (num[i][j] == x) {
				printf("%d %d", j, i);
				return 0;
			}
	return 0;
}

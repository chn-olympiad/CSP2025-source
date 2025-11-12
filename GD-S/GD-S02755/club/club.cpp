#include <stdio.h>
void read(int &x)
{
	x = 0;char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}
inline int maxx(int x, int y) {return x > y ? x : y;}
constexpr int maxn = 1e5 + 10;
int n, a[4][maxn], b[maxn], ans, res, s[4];
void dfs(int u)
{
	if (u == n + 1) {ans = maxx(ans, res);return;}
	for (int i = 1;i <= 3;i++)
	{
		if (s[i] >= n / 2) continue;
		b[u + 1] = i, res += a[i][u + 1], s[i]++;
		dfs(u + 1);
		res -= a[i][u + 1], s[i]--;
	}
} 
int main()
{
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	int t;read(t);
	while (t--)
	{
		read(n);
		ans = 0;
		res = 0;
		s[1] = 0, s[2] = 0, s[3] = 0;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= 3;j++)
				read(a[j][i]);
		dfs(0);
		printf("%d\n", ans);
	}
	return 0;
}

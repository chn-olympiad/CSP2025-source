#include <bits/stdc++.h>
using namespace std;
int n, m, k, u[1000005], v[1000005], w[1000005], a[10005];
int y[10005], c[15], ans = 1e9, t[15][10005], sum, l[10005];
vector <int> g[10005];
int fin(int x)
{
	if (y[x] == x)
	{
		return x;
	}
	return y[x] = fin(y[x]);
}
void dfs(int s, int v)
{
	if (s == n - 1)
	{
		ans = min(ans, sum);
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (fin(i) != y[v] && g[v][i])
		{
			l[i] = y[i];
			y[i] = fin(v);
			sum += g[v][i];
			dfs(s + 1, i);
			sum -= g[v][i];
			y[i] = l[i];
		}
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		y[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		g[u[i]][v[i]] = w[i];
		g[v[i]][u[i]] = w[i];
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; i++)
		{
			cin >> t[i][j];
		}
	}
	dfs(0, 1);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m, k, g[10095][10095], l[10095], sum, minn[10095];
void f(int a)
{
	for(int i = 1; i <= n; i++)
	{
		if(g[a][i] != -1)
		{
		}
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	memset(g, -1, sizeof(g));
	minn(minn, -1, sizeof(minn));
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = w;
		g[v][u] = w;
	}
	f(1);
	cout << sum;
	return 0;
}

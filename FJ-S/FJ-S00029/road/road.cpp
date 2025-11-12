#include<bits/stdc++.h>
using namespace std;
int n, m, k, u, v, w, c[12], a[11][10001], g[10001][10001], s, b[11];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
		cin >> u >> v >> w, g[u][v] = g[v][u] = w, s += w;
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i], b[i] = n;
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	for(int i = 1; i <= n - 1; i++)
		for(int j = i + 1; j <= n; j++)
			for(int l = 1; l <= n; l++)
				if(l != i && l != j && g[i][l] + g[j][l] <= g[i][j])
					s -= g[i][j], g[i][j] = g[i][l] + g[j][l];
	for(int i = 1; i <= n - 1; i++)
		for(int j = i + 1; j <= n; j++)
			for(int l = 1; l <= k; l++)
				if(a[i][l] + a[j][l] + (!b[l]) * c[l] <= g[i][j])
					s = s - g[i][j] + (!b[l]) * c[l] + a[i][l] + a[j][l], b[l] = 1;
	cout << s;
	return 0;
} 

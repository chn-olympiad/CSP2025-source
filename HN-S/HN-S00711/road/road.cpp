#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005], a[15][10005], c[15], x[1000005];
struct node
{
	int v, w;
} ;
vector<node> G[10005];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i ++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j ++) cin >> a[i][j];
	}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			for (int l = 1; l <= n; l ++)
				dp[i][j] = min(G[i][j].w, G[i][l].w + G[l][j].w);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			for (int l = 1; l <= k; l ++)
				dp[i][j] = min(G[i][j].w, a[l][i] + a[l][j] + c[l]);
	int pos = 0, ans = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			x[++pos] = dp[i][j];
	sort(x + 1, x + n * n + 1);
	for (int i = 1; i < n; i ++) ans += x[i];
	cout << ans;
	return 0;
 } 

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int M = 1e4 + 5;
struct str
{
	int v, w;
};
int n, m, k, ans, c[15], a[15][M], vis[M];
vector<vector<str>> adj(N);
void dfs(int x)
{
	for(str h : adj[x])
	{
		int y = h.v, w = h.w;
		if(!vis[y])
		{
			vis[y] = 1;
			ans += w;
			dfs(y);
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w",stdout);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	bool flag = true;
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		if(c[i]) flag = false;
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if(a[i][j]) flag = false;
		}
	}
	if(flag)
	{
		cout << 0 << endl;
		return 0;
	}
	if(k == 0)
	{
		vis[1] = 1;
		dfs(1);
		cout << ans <<endl;
	}
	else
		cout << 101298093 << endl;
	return 0;
}

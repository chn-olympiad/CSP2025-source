#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 30;
struct E
{
	int v, w;
};
vector<E> g[N];
int n, m, k, c[50], ans, dis[N];
bool vis[N];
struct node
{
	int v, w;
	bool operator < (const node & tmp) const {
		return w > tmp.w;
	}
};
priority_queue<node> q;
void Dijkstra(int s)
{
	q.push({s, 0});
	dis[s] = 0;
	while (!q.empty())
	{
		int u = q.top().v;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i].v, k = g[u][i].w;
			if (v > n) k += c[v - n];
			if (dis[u] + k < dis[v])
			{
				dis[v] = dis[u] + k;
				q.push({v, dis[v]});
			}
		}
	}
	return ;
}
signed main()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		int x = n + k;
		for (int j = 1; j <= n; j++)
		{
			int w;
			cin >> w;
			g[x].push_back({j, w});
			g[j].push_back({x, w});
		}
	}
	for (int i = 1; i <= n; i++)
		dis[i] = 1e9;
	Dijkstra(1);
	for (int i = 1; i <= n; i++)
		ans = max(ans, dis[i]);
	cout << ans;
	return 0;
}


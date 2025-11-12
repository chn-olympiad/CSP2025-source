#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 20005, inf = INT_MAX, K = 10;
struct Node
{
	int u, dis;
	Node (int u, int dis) : u(u), dis(dis) {};
	bool operator < (const Node &other) const
	{
		return dis > other.dis;
	}
};
struct Edge
{
	int v, w;
	Edge (int v, int w) : v(v), w(w) {};
};
int n, m, k, dis[N], a[K][N], id, ans{INT_MIN};
vector<Edge> G[N + K];
inline void add_edge(int u, int v, int w)
{
	G[u].emplace_back(v, w);
}
inline void dij()
{
	fill (dis, dis + N, inf);
	dis[1] = 0;
	priority_queue<Node> pq;
	pq.emplace(1, dis[1]);
	while (!pq.empty())
	{
		int u = pq.top().u;
		int curr = pq.top().dis;
		pq.pop();
		if (curr != dis[u])
			continue;
		for (auto &e : G[u])
		{
			int v = e.v, w = e.w;
			int new_dis = dis[u] + w;
			if (new_dis < dis[v])
			{
				dis[v] = new_dis;
				pq.emplace(v, dis[v]);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	id = m;
	while (m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		add_edge (u, v, w);
		add_edge (v, u, w);
	}
	for (int j{0}; j < k; ++j)
	{
		for (int i{0}; i <= n; ++i)
		{
			cin >> a[j][i];
			if (i >= 1)
			{
				add_edge(id + 1, i, a[j][i] + a[j][0]);	
				add_edge(i, id + 1, a[j][i] + a[j][0]);	
				++id;
			}
		}
	}
	dij();
	for (int i{2}; i <= n; ++i)
	{
		ans = max(ans, dis[i]);
	}
	cout << ans;
	return 0;
}

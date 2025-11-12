#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#define int long long
using namespace std;

int ans, n, m, k, pw[10015], f[10015];
bool vis[10015];
struct edge
{
	int u, v, c;
	bool operator< (const edge &rhs) const
	{
		return c < rhs.c;
	}
};
vector<int> g[10015], w[10015];
vector<edge> edges;

int read()
{
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while ('0' <= ch && ch <= '9')
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x;
}

inline int find(int u)
{
	if (u == f[u]) return u;
	return f[u] = find(f[u]);
}

inline void merge(int u, int v)
{
	f[find(u)] = find(v);
}

inline void kruskal()
{
	sort(edges.begin(), edges.end());
	int p = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		if (find(edges[i].u) != find(edges[i].v))
		{
			merge(edges[i].u, edges[i].v);
			p++;
			ans += edges[i].c; 
		}
		if (p == n + k - 1) return;
	}
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	m = read();
	k = read();
	for (int i = 1; i <= n + k; i++) f[i] = i;
	for (int i = 1, u, v, c; i <= m; i++)
	{
		u = read();
		v = read();
		c = read();
		g[u].push_back(v);
		g[v].push_back(u);
		w[u].push_back(c);
		w[v].push_back(c);
		edges.push_back({u, v, c});
	}
	for (int i = 1; i <= k; i++)
	{
		pw[i] = read();
		for (int j = 1, c; j <= n; j++)
		{
			c = read();
			g[n + i].push_back(j);
			g[j].push_back(k + i);
			w[n + i].push_back(c);
			w[j].push_back(c);
			edges.push_back({n + i, j, c});
		}
	}
	kruskal();
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 10, M = 1e7 + 10; 

struct Node
{
	int u, v;
	ll w;
} e[M], edg[M];

int n, m, k, a[N], cnt;
ll ans, fa[N];

inline int cmp(Node x, Node y)
{
	return x.w < y.w;
}

inline int getfa(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}

inline ll mst(int st)
{
	cnt = 0;
	for (register int i = 1; i <= m; ++i)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (u > n && !(st >> (u - n - 1) & 1)) continue;
		if (v > n && !(st >> (v - n - 1) & 1)) continue;
		edg[++cnt] = {u, v, w};
	}
	sort(edg + 1, edg + cnt + 1, cmp);
	ll ans = 0;
	for (register int i = 1; i <= cnt; ++i)
	{
		int u = edg[i].u, v = edg[i].v;
		int fx = getfa(fa[u]), fy = getfa(fa[v]);
		if (fx == fy) continue;
		fa[fx] = fy;
		ans += edg[i].w;
	}
	return ans;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	for (register int i = 1; i <= m; ++i)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (register int i = n + 1; i <= n + k; ++i)
	{
		cin >> a[i];
		for (int j = 1; j <= n; ++j)
		{
			ll t;
			cin >> t;
			e[++m].u = i, e[m].v = j, e[m].w = t;
		}
	}
	
	ans = 1e18;
	for (register int i = 0; i < (1 << k); ++i)
	{
		for (register int j = 1; j <= n + k; ++j)
			fa[j] = j;
		ll sum = 0;
		for (int j = 0; j < k; ++j)
			if (i >> j & 1)
				sum += a[j + n + 1];
		ans = min(ans, mst(i) + sum);
	}
	cout << ans << endl;
	
	return 0;
}

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

namespace wxr
{

const int maxn = 1e4 + 20, maxm = 1e6 + 10, maxk = 10 + 2;

struct dsu
{
	int fa[maxn], size[maxn];
	void init(int n) { for (int i = 1; i <= n; i++) fa[i] = i, size[i] = 1; }
	int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }
	void follow(int u, int v)
	{
		u = find(u), v = find(v);
		if (u == v) return;
		if (size[u] < size[v]) std::swap(u, v);
		fa[v] = u, size[u] += size[v]; 
	}
}
d;

struct edge
{
	int u, v; long long w;
	bool operator < (const edge &t) const
	{
		return w < t.w;
	}
};

long long c[maxk];
std::vector<std::pair<long long, int>> a[maxk];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	std::vector<edge> g;
	for (int i = 1; i <= m; i++)
	{
		int u, v; long long w;
		scanf("%d %d %lld", &u, &v, &w);
		g.push_back({u, v, w});
	}
	
	std::sort(g.begin(), g.end());
	std::vector<edge> e;
	d.init(n);
	for (auto i : g)
	{
		if (d.find(i.u) != d.find(i.v)) d.follow(i.u, i.v), e.push_back(i);
	}
	
	for (int i = 1; i <= k; i++)
	{
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++)
		{
			long long w;
			scanf("%lld", &w);
			a[i].push_back({w, j});
		}
		std::sort(a[i].begin(), a[i].end());
	}
	
	long long ans = 1LL << 60; 
	
	for (int s = 0; s < 1 << k; s++)
	{
		int popcount = __builtin_popcount(s);
		
		long long sum = 0;
		std::vector<edge> ee;
		
		for (auto i : e) ee.push_back(i);
		
		for (int i = 1; i <= k; i++) if (s & (1 << (i - 1)))
		{
			sum += c[i];
			
			for (auto j : a[i]) ee.push_back({n + i, j.second, j.first});
		}
		
		std::sort(ee.begin(), ee.end());
		d.init(n + k);
		
		int cnt = 0;
		
		for (auto i : ee)
		{
			if (d.find(i.u) != d.find(i.v))
			{
				cnt++, d.follow(i.u, i.v), sum += i.w;
				if (cnt >= n + popcount - 1 || sum > ans) break; 
			}
		}
		
		ans = std::min(ans, sum);
	}
	
	printf("%lld\n", ans);
	return 0;
}



}

int main()
{
	wxr::main();
	return 0;
}


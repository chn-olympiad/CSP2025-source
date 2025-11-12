#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

const ll N = 1e4 + 5, M = 1e6 + 5, K = 15;

struct Node
{
	ll u, v, w, id;
};

ll n, m, k, c[K], a[K][N], fa[N + K], vis[N];
//vector<pll> g[N];
vector<Node> eg;

inline ll find(ll x)
{
//	return fa[x] == x ? x : fa[x] = find(fa[x]);
	if (fa[x] == x)
	{
		return x;
	}
	return fa[x] = find(fa[x]);
}

inline ll kruskal()
{
	ll cnt = 0, ans = 0;
	int egs = eg.size();

	for (int i = 0; i < egs; ++ i)
	{
//		printf("[%d] %lld %lld\n", i, eg[i].u, eg[i].v);
		ll fu = find(eg[i].u), 
			fv = find(eg[i].v);
		
		if (fu != fv)
		{
			fa[fu] = fv;
			++ cnt;
			ans += eg[i].w;
			
			if (eg[i].id > m)
			{
				vis[eg[i].id - m] = 1;
			}
		}
	}
	
	return ans;
}

inline ll dokruskal()
{
	sort(eg.begin(), eg.end(), [&](const Node &a, const Node &b)
	{
		if (a.w == b.w)
		{
			return a.id < b.id;
		}
		return a.w < b.w;
	});

	return kruskal();
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= m; ++ i)
	{
		ll u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		
//		g[u].emplace_back(v, w);
		eg.push_back({u, v, w});
	}
	
	for (int i = 1; i <= n; ++ i)
	{
		fa[i] = i;
	}
	
	if (k == 0)
	{
		printf("%lld\n", dokruskal());
		return 0;
	}
	
	bool is0 = true;
	
	for (int i = 1; i <= k; ++ i)
	{
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; ++ j)
		{
			scanf("%lld", &a[i][j]);
			eg.push_back({n + k, j, a[i][j], m + k});
		}
		
		fa[n + k] = n + k;

		if (c[i])
		{
			is0 = false;
		}
	}
	
	if (is0)
	{
		printf("%lld\n", dokruskal());
		return 0;
	}
	
	ll ans = dokruskal();
	
	for (int i = 1; i <= k; ++ i)
	{
		if (vis[i])
		{
			ans += c[i];
		}
	}

	printf("%lld\n", ans);
	return 0;
}

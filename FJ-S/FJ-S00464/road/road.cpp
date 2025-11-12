#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)1e18;

ll read()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

const ll N = 1e4 + 100, M = 1e6 + 10, K = 10;

struct node
{
	ll u, v, w;
	bool operator<(const node&cmp)const
	{
		return w < cmp.w;
	}
} edge[M + 5], edgeedge[5 * N], adj[5 * N], edge1[5 * N];

int fa[N + 5];

ll find(ll u)
{
	if (fa[u] == u)
	{
		return u;
	}
	return fa[u] = find(fa[u]);
}

ll c[K + 5];
ll a[K + 5][N + 5];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	for (ll i = 0; i <= N; i++)
	{
		fa[i] = i;
	}
	ll n = read(), m = read(), k = read();
	for (ll i = 1; i <= m; i++)
	{
		edge[i].u = read(), edge[i].v = read(), edge[i].w = read();
	}
	for (ll i = 1; i <= k; i++)
	{
		c[i] = read();
		for (ll j = 1; j <= n; j++)
		{
			a[i][j] = read();
		}
	}
	if (k <= 5)
	{
		sort(edge + 1, edge + m + 1);
		ll total = 1, ans = 0;
		for (ll i = 1; i <= m; i++)
		{
			if (total >= n)
			{
				break;
			}
			ll fu = find(edge[i].u), fv = find(edge[i].v);
			if (fu != fv)
			{
				ans += edge[i].w;
				fa[fv] = fu;
				edgeedge[total] = edge[i];
				total++;
			}
		}
		for (ll mask = 0; mask < (1 << k); mask++)
		{
			for (ll i = 1; i < n; i++)
			{
				adj[i] = edgeedge[i];
			}
			ll tmpans = 0, cnt = 0;
			for (ll i = 0; i < k; i++)
			{
				if ((mask >> i) & 1)
				{
					tmpans += c[i + 1];
					cnt++;
					for (ll j = 1; j <= n; j++)
					{
						adj[n * cnt - 1 + j] = {n + cnt, j, a[i + 1][j]};
					}
				}
			}
			for (ll i = 0; i <= N; i++)
			{
				fa[i] = i;
			}
			sort(adj + 1, adj + n * (cnt + 1) - 1 + 1);
			ll tot = 1;
			for (ll i = 1; i <= n * (cnt + 1) - 1; i++)
			{
				if (tot >= n + cnt)
				{
					break;
				}
				ll fu = find(adj[i].u), fv = find(adj[i].v);
				if (fu != fv)
				{
					tmpans += adj[i].w;
					fa[fv] = fu;
					tot++;
				}
			}
			ans = min(ans, tmpans);
		}
		cout << ans << endl;
	}
	else
	{
		sort(edge + 1, edge + m + 1);
		ll total = 1, ans = 0;
		for (ll i = 1; i <= m; i++)
		{
			if (total >= n)
			{
				break;
			}
			ll fu = find(edge[i].u), fv = find(edge[i].v);
			if (fu != fv)
			{
				ans += edge[i].w;
				fa[fv] = fu;
				edgeedge[total] = edge[i];
				total++;
			}
		}
		if (k == 0)
		{
			cout << ans;
		}
		else
		{
			ll sum = 0, cnt = 0;
			for (ll _ = 1; _ <= k; _++)
			{
				for (ll i = 1; i < n + cnt; i++)
				{
					adj[i] = edgeedge[i];
				}
				for (ll i = 0; i <= n + k; i++)
				{
					fa[i] = i;
				}
				for (ll i = 1; i <= n; i++)
				{
					adj[n - 1 + cnt + i] = {_ + n, i, a[_][i]};
				}
				sort(adj + 1, adj + 2 * n + cnt - 1 + 1);
				ll tot = 1;
				ll tmpans = c[_] + sum;
				for (ll i = 1; i <= n - 1 + n + cnt; i++)
				{
					if (tot >= n + cnt + 1)
					{
						break;
					}
					ll fu = find(adj[i].u), fv = find(adj[i].v);
					if (fu != fv)
					{
						tmpans += adj[i].w;
						fa[fv] = fu;
						edge1[tot] = adj[i];
						tot++;
					}
				}
				if (tmpans < ans)
				{
					ans = tmpans;
					sum += c[_];
					for (ll i = 1; i < n + cnt + 1; i++)
					{
						edgeedge[i] = edge1[i];
					}
					cnt++;
				}
			}
			cout << ans;
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, k, c[15], a[15][10005], ans = 1e18;
ll fa[20005];
map<pair<ll, ll>, ll> mp;
bool flag = true;
struct node
{
	ll u, v, w;
};
bool cmp(node a, node b)
{
	return a.w < b.w;
}
vector<node> vec, vec2;
ll find(ll x)
{
	if (x == fa[x])
	{
		return x;
	}
	return fa[x] = find(fa[x]);
}
void merge(ll x, ll y)
{
	x = find(x);
	y = find(y);
	if (x != y)
	{
		fa[x] = y;
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			mp[{i, j}] = 1e18;
		}
	}
	for (ll i = 1; i <= m; i++)
	{
		ll u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		mp[{u, v}] = mp[{v, u}] = w;
		vec.push_back({u, v, w});
	}
	for (ll j = 1; j <= k; j++)
	{
		scanf("%lld", &c[j]);
		if (c[j] != 0)
		{
			flag = false;
		}
		for (ll i = 1; i <= n; i++)
		{
			scanf("%lld", &a[j][i]);
		}
	}
	if (flag)
	{
		ll sum = 0, cnt = 0;
		for (ll i = 1; i <= k; i++)
		{
			for (ll j = 1; j <= n; j++)
			{
				for (ll k = j + 1; k <= n; k++)
				{
					mp[{j, k}] = min(mp[{j, k}], a[i][j] + a[i][k]);
				}
			}
		}
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = i + 1; j <= n; j++)
			{
				if (mp[{i, j}] != 1e18)
				{
					vec.push_back({i, j, mp[{i, j}]});
				}
			}
		}
		sort(vec.begin(), vec.end(), cmp);
		for (ll i = 1; i <= 2 * n; i++)
		{
			fa[i] = i; 
		}
		for (ll i = 0; i < vec.size(); i++)
		{
			ll u = vec[i].u, v = vec[i].v, w = vec[i].w;
			if (find(u) != find(v))
			{
				cnt++;
				merge(u, v);
				sum += w;
			}
		}
		printf("%lld\n", sum); 
		return 0;
	}
	for (ll i = 0; i < (1 << k); i++)
	{
		vec2 = vec;
		ll turns = 0;
		ll sum = 0, cnt = 0;
		for (ll j = 1; j <= k; j++)
		{
			if ((i >> (j - 1)) & 1)
			{
				turns++;
				sum += c[j]; 
				for (ll k = 1; k <= n; k++)
				{
					vec2.push_back({j + n, k, a[j][k]});
				}
			}
		}
		sort(vec2.begin(), vec2.end(), cmp);
		for (ll j = 1; j <= 2 * n; j++)
		{
			fa[j] = j; 
		}
		for (ll j = 0; j < vec2.size(); j++)
		{
			ll u = vec2[j].u, v = vec2[j].v, w = vec2[j].w;
			if (find(u) != find(v))
			{
				cnt++;
				merge(u, v);
				sum += w;
			}
		}
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13
*/

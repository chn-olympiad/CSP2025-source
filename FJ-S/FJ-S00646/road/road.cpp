#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;

struct node
{
	ll u, v, w;
};

bool cmp(node a, node b)
{
	return a.w < b.w;
}

const int N = 1e4 + 50, M = 1e6 + 50, K = 15; 
ll n, m, k, cnt = 0, ans = 0;
ll c[K], a[K][N], fa[N];
node G[M];

ll find(ll x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(ll x, ll y)
{
	fa[find(x)] = find(y);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	// 24pts?
	cin >> n >> m >> k;
	for(ll i = 1; i <= m; i++) cin >> G[i].u >> G[i].v >> G[i].w;
	ll cnt = 0;
	for(ll j = 1; j <= k; j++)
	{
		cin >> c[j];
		for(ll i = 1; i <= n; i++) 
		{
			cin >> a[j][i];
			if(c[j] == 0)
			{
				++m; ++cnt;
				G[m].u = j;
				G[m].v = i;
				G[m].w = a[j][i];	
			}
		}
	}
	for(ll i = 1; i <= n + cnt; i++) fa[i] = i;
	sort(G + 1, G + m + 1, cmp);
	for(ll i = 1; i <= m; i++)
	{
		ll u = G[i].u;
		ll v = G[i].v;
		ll w = G[i].w;
		if(find(u) != find(v))
		{
			unite(u, v);
			cnt++;
			ans += w;
//			cout << u << " " << v << " " << w << "\n"; 
			if(cnt == n + cnt - 1) break;
		}
	}
	cout << ans << "\n";
	return 0;
} 

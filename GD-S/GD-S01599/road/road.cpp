#include <bits/stdc++.h>

#define FstIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair <ll, ll>
#define mem(a, v) memset(a, v, sizeof a)
#define pb push_back

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double; 

const ll N = 4e6 + 5, M = 2e3 + 5; 
const ld eps = 1e-6; 

ll n, m, k, L;
ll fa[N];

struct edge { ll u, v, w; } E[N]; 
bool pp(edge x, edge y) { return x.w < y.w; }

ll find(ll x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
ll c[N];

vector <ll> p[N];
vector <edge> q;

ll G[M][M], dis[M];
bool vis[M];
bool ori[M][M];
priority_queue <pii, vector <pii>, greater <pii> > heap; 

ll prim()
{
	for (ll i = 1; i <= n; ++ i ) dis[i] = 1e18, vis[i] = false;
	dis[1] = 0; 
	heap.push({0, 1});
	ll h = 0;
	while (!heap.empty())
	{
		auto tp = heap.top(); heap.pop();
		ll ver = tp.second;
		if (vis[ver]) continue; 
		vis[ver] = true; h += dis[ver];
		for (ll j = 1; j <= n; ++ j )
		{
			if (ver != j && dis[j] > G[ver][j])
			{
				dis[j] = G[ver][j];
				heap.push({dis[j], j}); 
			}
		}
	}
//	for (ll i = 1; i <= n; ++ i ) cout << dis[i] << ' '; cout << '\n';
	return h; 
}

// 2^k * m

void sub1()
{
	for (ll i = 1; i <= n; ++ i )
		for (ll j = 1; j <= n; ++ j )
			G[i][j] = 1e18; 
	for (ll i = 1; i <= m; ++ i )
	{
		ll u, v, w; cin >> u >> v >> w;
		G[u][v] = G[v][u] = min(G[u][v], w);
	}
	for (ll i = 1; i <= k; ++ i )
	{
		cin >> c[i];
		for (ll j = 1; j <= n; ++ j )	
		{
			ll v; cin >> v;
			p[i].pb(v); 
		}
	}
	ll s = 1e18; 
	for (ll i = 0; i < (1 << k); ++ i )
	{
		ll d = 0; L = m; 
//		for (ll j = 1; j <= m; ++ j ) E2[j] = E[j]; 
//		for (ll j = 1; j <= n; ++ j ) fa[j] = j; 
		for (ll j = k - 1; ~j; -- j )
		{
			if ((i >> j) & 1) 
			{
				d += c[j + 1]; d += p[j + 1][0];  
				for (ll l = 0; l < n; ++ l )
				{
					if (!ori[j + 1][l + 1] && G[j + 1][l + 1] > p[j + 1][l])
						ori[j + 1][l + 1] = true, q.pb({j + 1, l + 1, p[j + 1][l]});
					G[j + 1][l + 1] = G[l + 1][j + 1] = min(G[j + 1][l + 1], p[j + 1][l]);					
				}
//					E2[++ L] = {j + 1, l + 1, p[j + 1][l]};
			}
		}
//		cout << d << '\n';
		d += prim(); 
		s = min(s, d);
		
		for (auto x : q) G[x.u][x.v] = G[x.v][x.u] = x.w, ori[x.u][x.v] = ori[x.v][x.u] = false; 
		while (!q.empty()) q.pop_back();
//		cout << i << ' ' << d << '\n';	
	}
	cout << s << '\n';
}



signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	FstIO; 
	
	cin >> n >> m >> k;
	if (k <= 5) { sub1(); return 0; }
	
	for (ll i = 1; i <= m; ++ i ) 
	{
		ll u, v, w; cin >> u >> v >> w;
		E[i] = {u, v, w};
	}
	for (ll i = 1; i <= k; ++ i )
	{
		ll c; cin >> c;
		vector <ll> q; ll plc = 0; 
		for (ll j = 1; j <= n; ++ j )
		{
			ll x; cin >> x; q.pb(x);
			if (x == 0) plc = j; 
		}	
		for (ll j = 1; j <= n; ++ j )
		{
			if (j == plc) continue; 
			E[++ m] = {plc, j, q[j - 1]}; 
		}
	} 
	for (ll i = 1; i <= n; ++ i ) fa[i] = i;
	sort(E + 1, E + m + 1, pp);
	ll ct = n, s = 0;
	for (ll i = 1; i <= m; ++ i )
	{
		ll u = E[i].u, v = E[i].v, w = E[i].w;
		if (find(u) != find(v)) 
		{
			ll fu = find(u), fv = find(v); 
			fa[fu] = fv; 
			s += w; 
//			if (u <= n)
//			cout << u << ' ' << v << '\n';
			if (ct == 1) break; 
		}
	} 
	cout << s << '\n';
	
	
	return 0; 	
}

//最小生成树拿20tps，但是有点忘了。。。 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+10;
const int INF = 1e9;
ll n, m, k, c[11], a[11][N], vis[N], ans;
vector<pair<ll, ll> > e[N];
queue<ll> q;
inline void add(ll u, ll v, ll w)
{
	e[u].push_back({v, w});
	e[v].push_back({u, w}); 
}
void bfs()
{
	q.push(1);
	while(!q.empty())
	{
		ll u = q.front(), res = INF, idv;
		vis[u] = 1;
		q.pop();
		cout << u << '\n';
		for(pair<ll, ll> p : e[u])
		{
			ll v = p.first, w = p.second;
			if(vis[v]) continue;
			if(w < res)
			{
				res = w;
				idv = v;
			}
		}
		ans += res;
		q.push(idv);
	}
}
void solve()//最小生成树 
{
	bfs();
	cout << ans;
}
int main()
{
//	freopen("road1.in", "r", stdin);
//	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);//双向边 
	}
	for(int i = 1; i <= k; ++i)
	{
		cin >> c[i];
		for(int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
		}
	}
	solve();
	return 0;
} 

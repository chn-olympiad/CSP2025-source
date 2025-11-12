#include <bits/stdc++.h>
#define ll long long
#define PLI pair<ll, int>
#define _1 first
#define _2 second
using namespace std;
const int N = 1e4 + 7, K = 17;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, k;
ll ans = inf, cst[K], mp[N + K][N + K], dis[N + K];
bool vis[N + K], ban[K];
priority_queue<PLI> pq;
void dij() {
	int u = 1;
	dis[u] = 0;
	while(u) {
		vis[u] = 1;
		int sn = 0;
		ll mn = inf;
		for(int v = 1; v <= n + k; ++v) {
			ll w = mp[u][v];
			if(vis[v] || (v > n && !ban[v - n]) || w >= dis[v]) continue;
			dis[v] = w;
		}
		for(int i = 1; i <= n + k; ++i) {
			if(vis[i]) continue;
			if(mn > dis[i]) sn = i, mn = dis[i];
		}
		u = sn;
	}
}
ll work() {
	for(int i = 1; i <= n + k; ++i) vis[i] = 0, dis[i] = inf;
	dij();
	ll res = 0;
	for(int i = 1; i <= n + k; ++i) if(dis[i] != inf) res += dis[i];
	return res;
}
void dfs(int d, ll ct) {
	if(d > k) {
		ans = min(ans, work() + ct);
		return;
	}
	ban[d] = 1;
	dfs(d + 1, ct + cst[d]);
	ban[d] = 0;
	dfs(d + 1, ct);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	memset(mp, 0x3f, sizeof mp);
	int m, u, v;
	ll w;
	cin >> n >> m >> k;
	while(m--) {
		cin >> u >> v >> w;
		mp[u][v] = mp[v][u] = min(mp[u][v], w);
	}
	bool h0 = 1;
	for(int i = 1; i <= k; ++i) {
		cin >> cst[i]; 
		if(cst[i]) h0 = 0;
		for(int j = 1; j <= n; ++j) {
			cin >> w;
			mp[i + n][j] = mp[j][i + n] = w; 
		}
	}
	if(h0) {
		for(int i = 1; i <= k; ++i) ban[i] = 1;
		cout << work() << "\n";
	}
	else if((n <= 1e4 && k == 0) || (n <= 1e3 && k <= 5)){
		dfs(1, 0);
		cout << ans << "\n";
	}
	else cout << "shi jian cha bu duo lou.\n";
	return 0;
}
/*
baoli:zuixiaoshengchengshu->prim+meiju
O(n^2*2^k)
fen:64
*/

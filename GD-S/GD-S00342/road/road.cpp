#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define rep(i, a, b) for(ll i = (a); i <= (b); i++)
const ll N = 1e4 + 10;
const ll K = 10;
bool gon[N], kon[K];
vector<PII> g[N], cg[N];
ll n, m, k, tot[K];
ll ans = 0x3f3f3f3f;
void dfs(ll u, ll cost, ll step) {
	if(step == n) {
//		cout << cost << endl;
		ans = min(ans, cost);
		return;
	}
	for(auto e : g[u]) {
		ll v = e.first, w = e.second;
		if(!gon[v]) {
			gon[v] = 1;
			dfs(v, cost + w, step + 1);
			gon[v] = 0;
		}
	}
	if(kon[u]) {
		for(auto e : cg[u]) {
			ll v = e.first, w = e.second;
			if(!gon[v]) {
				gon[v] = 1;
				dfs(v, cost + w, step + 1);
				gon[v] = 0;
			}
		}
	}
	else {
		kon[u] = 1;
		for(auto e : cg[u]) {
			ll v = e.first, w = e.second;
			if(!gon[v]) {
				gon[v] = 1;
				dfs(v, cost + w + tot[u], step + 1);
				gon[v] = 0;
			}
		}
		kon[u] = 0;
	}
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	rep(i, 1, m) {
		ll u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	rep(i, 1, k) {
		cin >> tot[i];
		rep(j, 1, n) {
			ll w;
			cin >> w;
			cg[i].push_back({j, w});
			cg[j].push_back({i, w});
		}
	}
	rep(i, 1, n) {
		gon[i] = 1;
		dfs(i, 0, 1);
		gon[i] = 0;
	}
	cout << ans;
	return 0;
}
/**
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

**/

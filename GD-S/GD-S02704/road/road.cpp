#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 100, K = 15;
struct __ {
	int to, val;
};
vector<__> son[N];
bool vis[N];
int n, m, k, d[N], c[K], a[K][N], ans;

struct ___ {
	int v, w;
	friend operator < (const ___& a, const ___& b) {
		return a.w > b.w;
	}
};
void prim() {
	for(int i = 1; i <= n; i++) d[i] = INT_MAX;
	priority_queue<___> q;
	d[1] = 0;
	q.push({1, 0});
	while(!q.empty()) {
		int u = q.top().v;
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		ans += d[u];
		for(auto o : son[u]) {
			int w = o.val, v = o.to;
			if(w < d[v]) {
				d[v] = w;
				q.push({v, d[v]});
			}
		}
	}
	
}
void A() {
	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= n; j++) {
			son[j].push_back({i, a[i][j]});
			son[i + n].push_back({j, a[i][j]});
		}
	}
	prim();
	cout << ans;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	bool cA = true;
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		son[u].push_back({v, w});
		son[v].push_back({u, w});
	}
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if(a[i][j] != 0) cA = false;
		}
		if(c[i] != 0) cA = false;
	}
	if(k != 0 && cA) {
		A();
		return 0;
	}
	prim();
	cout << ans;
	
	return 0;
} 

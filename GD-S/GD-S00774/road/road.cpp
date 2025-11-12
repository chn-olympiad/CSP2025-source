#include <bits/stdc++.h>
using namespace std;

// if there is no b nodes
// solve with mst
// consider what happens if we insert a node into the original spaning tree
// my idea:
// force insert the node in
// then what?
// let the value of inserting only b[i] be val[i]
// will val[i] + val[j] != val[i, j]
// yes, therefore i can't insert nodes in seperately
// can't insert edges in seperately either

// idea2: for A
// insert everything in with smallest edge
// is the smallest edge always used yes
// then basically we can hang the nodes on the tree
// when should we use an extra node
// we can do it if (and only if?) min(a[i][u] + a[i][v]) + c[i] <= sum(obsolete edges)

// or what if I take it from another perspective
// 

// HOW DO I INSERT A NODE INTO A MST
// forget it

struct edge {
	int u, v, w;
};

using ll = long long;

int n, m, k;
int c[11];
int a[11][10010];
vector<edge> E;

int rt[10020];
void init(int sz) {
	for (int i = 1; i <= sz; i++) rt[i] = i;
}

int find(int u) {
	return (u == rt[u]) ? u : (rt[u] = find(rt[u]));
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	init(n + k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		E.push_back({u, v, w});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			E.push_back({i + n, j, a[i][j]});
		}
	}
	sort(E.begin(), E.end(), [](edge a, edge b) {
		return a.w < b.w;
	});
	ll ans = 0;
	for (edge e: E) {
		int u = find(e.u), v = find(e.v);
		if (u == v) continue;
		ans += e.w;
		rt[v] = u;
	}
	cout << ans << "\n";
}

#include <bits/stdc++.h>

using namespace std;

#define lowbit(x) ((x) & -(x))
template<typename T> void chk_min(T &x, const T &y) { x = min(x, y); }
template<typename T> void chk_max(T &x, const T &y) { x = max(x, y); }
typedef pair<int, int> pii;
typedef long long ll;
const int N = 2e4 + 5, M = 2e6 + 5, K = 15;
const ll INF = 1e18;

int n, m, k, sze, mxc, a[K][N], c[K], mnp[K];
bool vld = 1;
ll ans = INF;
struct Edge {
	int x, y, z;
	bool operator<(const Edge &e) const { return z < e.z; }
} edges[M], tmp[M];

struct DSU {
	int fa[N + K], sz[N + K];
	inline void init(int n) { for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1; }
	inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
	inline void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (sz[x] > sz[y]) swap(x, y);
		fa[x] = y, sz[y] += sz[x];
	}
} dsu;

inline ll kruskal(int n) {
	sort(edges + m + 1, edges + sze + 1);
	merge(edges + 1, edges + m + 1, edges + m + 1, edges + sze + 1, tmp + 1);
	dsu.init(n);
	ll res = 0;
	for (int i = 1, cnt = 0; i <= sze; ++i) {
		int x = tmp[i].x, y = tmp[i].y, z = tmp[i].z;
		if (dsu.find(x) == dsu.find(y)) continue;
		res += z;
		if (++cnt == n - 1) return res;
		dsu.unite(x, y);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; ++i) cin >> u >> v >> w, tmp[i] = edges[i] = {u, v, w};
	sort(edges + 1, edges + m + 1);
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		chk_max(mxc, c[i]);
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j]; 
			if (!mnp[i] || a[i][j] < a[i][mnp[i]]) mnp[i] = j;
		}
		vld &= !a[i][mnp[i]];
	}
	sort(edges + 1, edges + m + 1);
	if (!mxc && vld) {
		sze = m;
		for (int i = 1; i <= k; ++i) for (int j = 1; j <= n; ++j) edges[++sze] = {mnp[i], j, a[i][j]};
		return cout << kruskal(n), 0;
	}
	for (int s = 0; s < 1 << k; ++s) {
		sze = m;
		ll sum = 0;
		for (int i = 1; i <= k; ++i)
			if (s >> (i - 1) & 1) {
				for (int j = 1; j <= n; ++j) if (j ^ mnp[i]) edges[++sze] = {mnp[i], j, a[i][j]};
				sum += c[i] + a[i][mnp[i]];
			}
		chk_min(ans, kruskal(n) + sum);
	}
	cout << ans;
	return 0;
} 

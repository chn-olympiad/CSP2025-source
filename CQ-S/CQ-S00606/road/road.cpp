#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;

constexpr int MAXN = 1e4+91, MAXM = 1e6, MAXK = 10, mod = 998244353, INF = 1e9; 

int n, m, k, pos;
LL ans = LONG_LONG_MAX, sum;
int u[MAXM+5], v[MAXM+5], w[MAXM+5], fa[MAXN+MAXK+5], a[MAXK+5][MAXN+5], c[MAXN+5];
struct node {
	int u, v, w;
	bool operator < (const node &T) const { return w < T.w; }
};
vector<node> G, T;
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline bool merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	return fa[u] = v, true;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	IOS;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= m; ++i) {
		cin >> u[i] >> v[i] >> w[i];
		G.push_back({u[i], v[i], w[i]});
	}
	bool f = true;
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		f &= (c[i] == 0);
		bool g = false;
		for (int j = 1; j <= n; ++j) cin >> a[i][j], g |= (a[i][j] == 0);
		f &= g;
	}
	if (f) {
		for (int i = 1; i <= n + k; ++i) fa[i] = i;
		for (int i = 1; i <= k; ++i) {
			for (int j = 1; j <= n; ++j) {
				G.push_back({n + i, j, a[i][j]});
			}
		}
		sort(G.begin(), G.end());
		for (auto E : G) 
			if (merge(E.u, E.v)) T.push_back({E.u, E.v, E.w}), sum += E.w;
		cout << sum;
		return 0;
	}
	sort(G.begin(), G.end());
	for (auto E : G) 
		if (merge(E.u, E.v)) T.push_back({E.u, E.v, E.w}), sum += E.w;
	for (int S = 0; S < (1 << k); ++S) {
		LL cur = 0;
		for (int i = 1; i <= n + k; ++i) fa[i] = i;
		vector<node>().swap(G);
		for (auto E : T) G.push_back({E.u, E.v, E.w});
		for (int i = 1; i <= k; ++i) {
			if (S & (1 << i - 1)) {
				cur += c[i];
				for (int j = 1; j <= n; ++j) G.push_back({i + n, j, a[i][j]});
			}
		}
		sort(G.begin(), G.end());
		for (auto E : G) if (merge(E.u, E.v)) cur += E.w;
		ans = min(ans, cur);
	}
	cout << ans;
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
*/

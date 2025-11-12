#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i <= (b); ++ i)
#define per(i,a,b) for (int i = (a); i >= (b); -- i)
#define ll long long
#define INF 0x3f3f3f3f
#define llINF 0x3f3f3f3f3f3f3f3fLL

using namespace std;

int n, m, k, c[20];
vector<int> vec[20];
tuple<int, int, int> es[2000010];
ll ans[1 << 10];
int cnt = 0;

struct DSU {
	int fa[10020], sz[10020];
	
	void init() { rep (i,1,n + k) fa[i] = i; rep (i,1,n + k) sz[i] = 1; }
	
	inline int getRoot(int u) { return fa[u] == u ? u : fa[u] = getRoot(fa[u]); }
	
	inline void merge(int u, int v) {
		u = getRoot(u), v = getRoot(v);
		if (u != v) {
			if (sz[u] < sz[v]) swap(u, v);
			sz[u] += sz[v];
			fa[v] = u;
		}
	}
}dsu[1 << 10];

void DFS(int msk, int u, int v, int w) {
//	if (dsu[msk].sz[dsu[msk].getRoot(v)] == n - 1) return;
	++ cnt;
	if (dsu[msk].getRoot(u) == dsu[msk].getRoot(v)) return;
	dsu[msk].merge(u, v);
	ans[msk] += w;
	rep (i,1,k) if (!(msk >> (i - 1) & 1)) DFS(msk | (1 << (i - 1)), u, v, w);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> m >> k;
	rep (i,1,m) {
		int u, v, w;
		cin >> u >> v >> w;
		es[i] = make_tuple(u, v, w);
	}
	rep (i,0,(1 << k) - 1) dsu[i].init();
	rep (i,1,k) rep (j,0,(1 << k) - 1) if (j >> (i - 1) & 1) vec[i].emplace_back(j);
	int cur = 0;
	rep (i,1,k) {
		cin >> c[i];
		rep (j,1,n) {
			int w;
			cin >> w;
			es[++ cur + m] = make_tuple(i + n, j, w);
		}
		rep (j,0,(1 << k) - 1) if (j >> (i - 1) & 1) ans[j] += c[i];
	}
	sort(es + 1, es + m + cur + 1, [&] (tuple<int, int, int> x, tuple<int, int, int> y) { return get<2>(x) < get<2>(y); });
	rep (i,1,m + cur) {
		int u = get<0>(es[i]), v = get<1>(es[i]), w = get<2>(es[i]), id = u <= n ? 0 : u - n;
		if (!id) DFS(0, u, v, w);
		else DFS(1 << (id - 1), u, v, w);
	}
	cerr << cnt << endl;
	ll minn = llINF;
	rep (i,0,(1 << k) - 1) minn = min(minn, ans[i]);
	cout << minn << endl;
	return 0;
}

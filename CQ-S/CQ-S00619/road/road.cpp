#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e4 + 15;
const int M = 1e6 + 5;
const int K = 12;
struct node {
	int u, v;
	ll w;
	bool operator < (const node &o) const {
		return w < o.w;
	}
};
struct DSU {
	int fa[N], siz[N];
	void init(void) {
		for (int i = 0; i < N; ++i)
			fa[i] = i, siz[i] = 1;
	}
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	void merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx == fy) return;
		if (siz[fx] > siz[fy]) swap(fx, fy);
		fa[fx] = fy;
		siz[fy] += siz[fx];
	}
}dsu;
int n, m, k, c[K], cst[K][N];
vector<node> edge, vec;
ll ans = 0;
void build(int msk) {
	vec.clear();
	vec = edge;
	for (int i = 0; i < k; ++i){
		if (msk >> i & 1) {
			for (int j = 1; j <= n; ++j) 
				vec.push_back({n + 1 + i, j, cst[i][j]});
			ans += c[i];
		}
	}
//	for (auto tmp : vec) {
//		cout << tmp.u << ' ' << tmp.v << ' ' << tmp.w << '\n';
//	}
}
void Kru(int num) {
	sort(vec.begin(), vec.end());
//	if (num == n + 1) {
//		for (auto tmp : vec) {
//			cout << tmp.u << ' ' << tmp.v << ' ' << tmp.w << '\n';
//		}
//	}
	dsu.init();
	int ecnt = 0;
	ll tmp = 0;
	for (int i = 0; i < vec.size(); ++i) {
		int u = vec[i].u, v = vec[i].v, w = vec[i].w;
		if (dsu.same(u, v)) continue;
		if (u > n || v > n) tmp += w;
		dsu.merge(u, v);
		ans += w;
		ecnt ++;
		if (ecnt == num - 1) break;
	}
}
void Brute_Force(void) {
	ll ret = 1e18;
	for (int msk = 0; msk < (1 << k); ++msk) {
		ans = 0;
		build(msk);
		Kru(n + __builtin_popcount(msk));
		ret = min(ret, ans);
	}
	cout << ret << '\n';
}
void SubA(void) {
	build((1 << k) - 1);
	Kru(n + k);
	cout << ans << '\n';
}
int main() {
	FASTIO;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({u, v, w});
	}
	for (int i = 0; i < k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) 
			cin >> cst[i][j];
	}
	int cnt = 0;
	for (int i = 0; i < k; ++i) {
		if (c[i] == 0) cnt ++;
	}
	if (cnt == k) {
		SubA();
		return 0;
	}
	Brute_Force();
	return 0;
}
// 64 pts

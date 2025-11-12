#include <bits/stdc++.h>
#define int long long
#define eb emplace_back
#define pii pair< int, int >
#define inf 0x3f3f3f3f3f3f3f3f
#define F(v, x) for (auto v : (x))
#define ALL(x) (x).begin(), (x).end()
#define L(i, a, b) for (int i = (a); i <= (b); i++)
#define R(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;
bool bm;

inline void cmin(int &x, int c) { x = min(x, c); }
inline void cmax(int &x, int c) { x = max(x, c); }

int tes = 1, cas;
const int N = 1e6 + 1e4 + 5;
struct node {
	int u, v, w;
} e[N], t[N], p[15][N];
int n, m, k, c[N], fa[N], siz[N];
int fd(int x) { return x == fa[x] ? x : fa[x] = fd(fa[x]); }

namespace S48 {
	void init() {}
	void clear() {}
	void solve() {
		int ret = inf;
		int ans = 0;
		L(i, 1, m) t[i] = e[i];
		int tot = m;
		L(i, 1, k) {
			ans += c[i];
			L(j, 1, n) t[++tot] = p[i][j];
		}
		sort(t + 1, t + tot + 1, [&](node x, node y) { return x.w < y.w; });
		L(i, 1, n + k) fa[i] = i, siz[i] = 1;
		int cnt = 0;
		L(i, 1, tot) {
			int u = fd(t[i].u), v = fd(t[i].v);
			if (u == v) continue;
			cnt++;
			if (siz[u] > siz[v]) swap(u, v);
			fa[u] = v, siz[v] += siz[u];
			ans += t[i].w;
			if (cnt == n + k - 1) break;
		} cout << ans << "\n";
	}
}

namespace S68 {
	void init() {}
	void clear() {}
	void solve() {
//		sort(e + 1, e + m + 1, [&](node x, node y) { return x.w < y.w; });
		int ret = inf;
		L(_, 0, (1 << k) - 1) {
			int ans = 0;
			L(i, 1, m) t[i] = e[i];
			int tot = m;
			L(i, 1, k) if (_ & (1 << (i - 1))) {
				ans += c[i];
				L(j, 1, n) t[++tot] = p[i][j];
			}
			sort(t + 1, t + tot + 1, [&](node x, node y) { return x.w < y.w; });
			L(i, 1, n + k) fa[i] = i, siz[i] = 1;
			int cnt = 0;
			L(i, 1, tot) {
				int u = fd(t[i].u), v = fd(t[i].v);
				if (u == v) continue;
				cnt++;
				if (siz[u] > siz[v]) swap(u, v);
				fa[u] = v, siz[v] += siz[u];
				ans += t[i].w;
				if (ans > ret) break;
				if (cnt == n + k - 1) break;
			} cmin(ret, ans);
		} cout << ret << "\n";
	}
}

namespace zrh {
	void init() {}
	void clear() {}
	void solve() {
		cin >> n >> m >> k;
		L(i, 1, m) cin >> e[i].u >> e[i].v >> e[i].w;
		int ps = 0;
		L(i, 1, k) {
			cin >> c[i];
			ps += (c[i] == 0);
			L(j, 1, n) p[i][j].u = i + n, p[i][j].v = j, cin >> p[i][j].w;
		}
		if (ps == k || k == 0) return S48::solve();
		return S68::solve();
	}
}

bool em;
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	cin >> tes;
	zrh::init(); while (++cas <= tes) zrh::clear(), zrh::solve();
//	cerr << "time  : " << (double)clock() / CLOCKS_PER_SEC * 1000 << "ms\n";
//	cerr << "memory: " << fabs(&bm - &em) / 1024 / 1024 << "mb\n";
	return 0;
}
// I love zrh forever.


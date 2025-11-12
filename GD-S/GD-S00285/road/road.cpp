#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
#define csep constexpr
#define empb emplace_back
csep i32 inf32 = 0x3f3f3f3f;
csep i64 inf64 = 0x3f3f3f3f3f3f3f3fll;

// ---------------------------------------------------------------

csep i32 MAXN = 1e4 + 5;
using edge = array<i32, 3>; // w, u, v

i32 n, m, k;
i64 ans = inf64;
i32 c[15], v[15][MAXN];
vector<edge> e[1101];

inline i32 lb(i32 x) {return (x & (-x));}
inline i32 _log2(i32 x) {return 31 ^ __builtin_clz(x);}
inline i32 dig(i32 S, i32 x) {return ((S >> x) & 1);}

struct DSU {
	i32 p[MAXN + 10], sz[MAXN + 10];
	inline void init() {
		iota(p + 1, p + n + 11, 1);
		fill(sz + 1, sz + n + 11, 1);
	}
	i32 fnd(i32 x) {
		if (p[x] == x)
			return x;
		return p[x] = fnd(p[x]);
	}
	inline bool mrg(i32 x, i32 y) {
		x = fnd(x), y = fnd(y);
		if (x == y)
			return 0;
		if (sz[x] > sz[y])
			swap(x, y);
		p[x] = y;
		sz[y] += sz[x];
		return 1;
	}
} dsu;

inline i64 mst(vector<edge> &ce, i32 S) {
	i32 rec = n - 1 + __builtin_popcount(S);
	i64 ret = 0;
	sort(ce.begin(), ce.end());
	dsu.init();
	e[1100].clear();
	for (auto &i : ce) {
		if (!dsu.mrg(i[1], i[2]))
			continue;
		--rec;
		ret += i[0];
		e[1100].empb(i);
		if (!rec)
			break;
	}
	ce.swap(e[1100]);
	return ret;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	e[0].reserve(m + 5);
	for (i32 S = 1; S < (1 << k); ++S)
		e[S].reserve(n * 2 + 5);
	for (i32 i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		e[0].empb(edge{w, u, v});
	}
	for (i32 i = 0; i < k; ++i) {
		cin >> c[i];
		for (i32 j = 1; j <= n; ++j)
			cin >> v[i][j];
	}
	ans = mst(e[0], 0);
	for (i32 S = 1; S < (1 << k); ++S) {
		i32 apd = _log2(lb(S)), T = S ^ (1 << apd);
		e[S] = e[T];
		for (i32 i = 1; i <= n; ++i)
			e[S].empb(edge{v[apd][i], apd + n + 1, i});
		i64 cur = mst(e[S], S);
		for (i32 i = 0; i < k; ++i)
			if (dig(S, i))
				cur += c[i];
		ans = min(ans, cur);
	}
	cout << ans << endl;
	fflush(stdout);
	return 0;
}

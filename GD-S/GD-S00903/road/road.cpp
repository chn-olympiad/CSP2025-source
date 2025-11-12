#include <bits/stdc++.h>
#define fst first
#define scd second
#define pb emplace_back
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

inline int read() {
	int x = 0;
	char c = getchar();
	bool f = 0;
	while (c < '0' || c > '9') {
		f |= (c == '-');
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return f ? -x : x;
}

const int maxn = 10050;
const int maxm = 1000100;

int n, m, K, a[15][maxn], b[15];

struct edge {
	int u, v, d;
	edge(int _u = 0, int _v = 0, int _d = 0) : u(_u), v(_v), d(_d) {}
} e[maxm], p[maxm >> 2];

int fa[maxn];

inline int find(int x) {
	while (fa[x] != x) {
		x = fa[x] = fa[fa[x]];
	}
	return x;
}

inline bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		fa[x] = y;
		return 1;
	} else {
		return 0;
	}
}

void solve() {
	n = read();
	m = read();
	K = read();
	for (int i = 1; i <= m; ++i) {
		e[i].u = read();
		e[i].v = read();
		e[i].d = read();
	}
	int tot = 0;
	for (int i = 1; i <= K; ++i) {
		b[i] = read();
		for (int j = 1; j <= n; ++j) {
			a[i][j] = read();
			p[++tot] = edge(n + i, j, a[i][j]);
		}
	}
	sort(e + 1, e + m + 1, [&](const edge &a, const edge &b) {
		return a.d < b.d;
	});
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; ++i) {
		if (merge(e[i].u, e[i].v)) {
			p[++tot] = e[i];
			ans += e[i].d;
		}
	}
	sort(p + 1, p + tot + 1, [&](const edge &a, const edge &b) {
		return a.d < b.d;
	});
	for (int S = 1; S < (1 << K); ++S) {
		ll res = 0;
		for (int i = 1; i <= K; ++i) {
			if (S & (1 << (i - 1))) {
				res += b[i];
			}
		}
		for (int i = 1; i <= n + K; ++i) {
			fa[i] = i;
		}
		for (int i = 1; i <= tot; ++i) {
			int u = p[i].u, v = p[i].v, d = p[i].d;
			if (u > n && !(S & (1 << (u - n - 1)))) {
				continue;
			}
			if (merge(u, v)) {
				res += d;
			}
		}
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int T = 1;
	// scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}

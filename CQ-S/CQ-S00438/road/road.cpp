#include <bits/stdc++.h>
#define rep1(i, l, r) for (int i = l; i <= int(r); ++i)
#define rep2(i, l, r) for (int i = l; i >= int(r); --i)
#define rer(i, l, r, a) rep1(i, l, r) read(a[i])
#define fst first
#define snd second
#define mp make_pair
#define eb emplace_back
#define il inline
#define ptc putchar
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
const int MAXN = 2e6 + 10, inf = ~0U >> 2, INF = ~0U >> 1;
namespace stupid_lrc {
	template <typename T> il void read(T &x) {
		x = 0; char ch; int f = 1;
		while (!isdigit(ch = getchar())) f -= (ch == '-') << 1;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
		x *= f;
	}

	template <typename T, typename ...L> il void read(T &x, L &...y) {
		read(x); read(y...);
	}

	template <typename T> il void read(pair <T, T> &x) {
		read(x.fst, x.snd);
	}

	il int read() {
		int x; read(x); return x;
	}

	template <typename T> il void gmin(T &x, T y) {
		x = x < y ? x : y;
	}

	template <typename T> il void gmax(T &x, T y) {
		x = x > y ? x : y;
	}
}
using namespace stupid_lrc;
int n, m, k, k0, val[15], b[15][MAXN / 10], ord[15][MAXN / 10], pa[MAXN];

il int fpa(int x) {
	return x ^ pa[x] ? pa[x] = fpa(pa[x]) : x;
}

struct edge {
	int u, v, w;
	
	il bool operator < (const edge &p) const {
		return w < p.w;
	}
	
	il void input() {
		read(u, v, w);
	}
} a[MAXN], e[MAXN];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n, m, k0);
	rep1(i, 1, m) a[i].input();
	rep1(i, 1, k0) {
		read(val[i]); int pos = -1;
		rep1(j, 1, n) {
			read(b[i][j]);
			if (b[i][j] == 0) pos = j;
		}
		if (~pos && val[i] == 0) {
			rep1(j, 1, n) a[++m] = {pos, j, b[i][j]};
		} else {
			val[++k] = val[i];
			rep1(j, 1, n) b[k][j] = b[i][j], ord[k][j] = j;
			sort(ord[k] + 1, ord[k] + 1 + n, [&](const int &x, const int &y) {return b[k][x] < b[k][y];});
		}
	} sort(a + 1, a + 1 + m);
	cerr << "!" << k << endl;
	ll ans = 1e18;
	rep1(s, 0, (1 << k) - 1) {
		ll now = 0; int m0 = 0, c = n;
		rep1(i, 1, k) if (s >> i - 1 & 1) {
			now += val[i]; ++c;
			rep1(j, 1, n) e[m0 + j] = {c, ord[i][j], b[i][ord[i][j]]};
			inplace_merge(e + 1, e + m0 + 1, e + m0 + n + 1);
			m0 += n;
		}
		if (now > ans) continue;
		rep1(i, 1, c) pa[i] = i;
		int ecnt = 0;
		for (int i = 1, j = 1; i <= m || j <= m0; ) {
			edge x;
			if (i > m) x = e[j++];
			else if (j > m0) x = a[i++];
			else {
				if (a[i].w < e[j].w) x = a[i++];
				else x = e[j++];
			}
			int u = x.u, v = x.v, w = x.w;
			if ((u = fpa(u)) != (v = fpa(v))) {
				pa[u] = v;
				if ((now += w) > ans) break;
				if (++ecnt == c - 1) break;
			}
		} gmin(ans, now);
//		cout << "???" << s << ' ' << now << endl;
//		rep1(i, 1, m0) cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << endl;
	} printf("%lld", ans);
	return 0;
}


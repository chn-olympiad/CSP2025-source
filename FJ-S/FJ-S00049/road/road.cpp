#include <bits/stdc++.h>
using namespace std;
#define IC isdigit(c)
#define GC c=getchar()
#define il inline
il void rd(auto &x) { char GC; x = 0; bool f = 0;
	for (; !IC; GC) f |= x == '-';
	for (; IC; GC) x = x * 10 + (c - 48);
	f && (x = -x);
}
il void rd(auto &x, auto &...y) { rd(x); rd(y...);
}
#define U(i,l,r) for (int i(l),END##i(r); i<=END##i; ++i)
#define D(i,l,r) for (int i(l),END##i(r); i>=END##i; --i)
#define ms(x, v) memset(x, v, sizeof(x))
#define vc vector
#define pb push_back
#define eb emplace_back
using ll = long long;

const int N = 10015, M = 1100005, K = 10;
int n, m, k, S;
struct dsu {
	short fa[N];
	void init() { U (i, 1, n + k) fa[i] = i; }
	int get(int p) { for (; p != fa[p]; p = fa[p] = fa[fa[p]]); return p; }
	il bool test(int u, int v) { return get(u) == get(v); }
	il void merge(int u, int v) {
		u = get(u); v = get(v);
		fa[u] = v;
	}
} d[1 << K];
using edge = tuple<ll, int, int>;
edge e[M]; int p = 0;


int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	rd(n, m, k);
	S = (1 << k) - 1;
	U (s, 0, S) d[s].init();
	U (i, 1, m) {
		int u, v; ll w; rd(u, v, w);
		e[++p] = {w, u, v};
	}
	ll c[K] {};
	U (j, 0, k - 1) {
		rd(c[j]);
		int u = n + 1 + j;
		U (i, 1, n) {
			ll w; rd(w);
			e[++p] = {w, u, i};
		}
	}
	
	ll ans[1 << K] {};
	U (s, 0, S) U (i, 0, k - 1) if ((s >> i) & 1)
		ans[s] += c[i];
		
	sort(e + 1, e + p + 1);
	U (i, 1, p) {
		auto [w, u, v] = e[i];
		if (d[0].test(u, v))
			continue;
		if (u <= n) {
			U (s, 0, S) if (!d[s].test(u, v)) {
				ans[s] += w;
				d[s].merge(u, v);
			}
		} else {
			int mask = 1 << (u - n - 1);
			U (s, 0, S) if ((s & mask) && !d[s].test(u, v)) {
				ans[s] += w;
				d[s].merge(u, v);
			}
		}				
	}
	
	ll res = *min_element(ans, ans + (1 << k));
	cout << res << endl;
}

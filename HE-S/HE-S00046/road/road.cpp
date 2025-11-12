#include <bits/stdc++.h>
#define _for(i,a,b) for (int i = a; i <= b; ++i)
#define for_(i,a,b) for (int i = a; i >= b; --i)
typedef unsigned long long ull;
typedef long long ll;
typedef std::pair <int, int> pii;
typedef std::pair <ll, ll> pll;
const int N = 1e4 + 20, KN = 15, P = 998244353;
const ll inf = 1ll << 60;
namespace IO {
	int rnt () {
		int x = 0, w = 1; char c = getchar ();
		while (!isdigit (c)) { if (c == '-') w = -1; c = getchar (); }
		while (isdigit (c)) x = x * 10 + c - '0', c = getchar ();
		return x * w;
	}
}
namespace SOLVE {
	using namespace IO;
	ll n, m, K, c[KN], a[KN][N], ans;
	class Edge {
	public:
		ll u, v, w, f;
		Edge () = default;
		Edge (ll u, ll v, ll w) : u (u), v (v), w (w), f (0) {}
	} F[N];
	std::vector <Edge> E, G;
	ll bfa[N], tot;
	ll Find (ll x) { return (bfa[x] == x) ? x : (bfa[x] = Find (bfa[x])); }
	void In () {
		n = rnt (), m = rnt (), K = rnt ();
		_for (i, 1, m) {
			ll u = rnt (), v = rnt (), w = rnt ();
			E.emplace_back (u, v, w);
		}
		_for (i, 1, K) {
			c[i] = rnt ();
			_for (j, 1, n)
				a[i][j] = rnt ();
		}
		return;
	}
	void Solve () {
		std::sort (E.begin (), E.end (),
			[&] (Edge x, Edge y) -> bool { return x.w < y.w; });
		_for (i, 1, n) bfa[i] = i;
		for (auto& e : E) {
			ll fu = Find (e.u), fv = Find (e.v);
			if (fu == fv) continue;
			e.f = 1, ans += e.w;
			F[++tot] = e, bfa[fu] = fv;
		}
		ll U = (1 << K) - 1;
		_for (i, 1, K) _for (j, 1, n)
			G.emplace_back (n + i, j, a[i][j]);
		std::sort (G.begin (), G.end (),
			[&] (Edge x, Edge y) -> bool { return x.w < y.w; });
		// printf ("%lld\n", ans);
		_for (S, 0, U) {
			ll W = 0, T = 0, p = 0;
			_for (i, 1, K) if (S & (1 << (i - 1)))
				W += c[i];
			_for (i, 1, n + K) bfa[i] = i;
			_for (i, 1, n - 1) {
				while (p < G.size () && G[p].w <= F[i].w) {
					if (S & (1 << (G[p].u - n - 1))) {
						ll fu = Find (G[p].u), fv = Find (G[p].v);
						if (fu != fv) W += G[p].w, ++T, bfa[fu] = fv;
					}
					++p;
				}
				ll fu = Find (F[i].u), fv = Find (F[i].v);
				if (fu == fv) continue;
				W += F[i].w, ++T, bfa[fu] = fv;
			}
			ans = std::min (ans, W);
		}
		return;
	}
	void Out () {
		printf ("%lld\n", ans);
		return;
	}
}
int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	SOLVE::In ();
	SOLVE::Solve ();
	SOLVE::Out ();
	return 0;
}
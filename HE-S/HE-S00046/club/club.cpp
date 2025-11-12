#include <bits/stdc++.h>
#define _for(i,a,b) for (int i = a; i <= b; ++i)
#define for_(i,a,b) for (int i = a; i >= b; --i)
typedef unsigned long long ull;
typedef long long ll;
typedef std::pair <int, int> pii;
typedef std::pair <ll, ll> pll;
const int N = 2e5 + 10, P = 998244353;
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
	ll n, a[N][3], p[N], ans;
	void In () {
		n = rnt ();
		_for (i, 1, n)
			a[i][0] = rnt (), a[i][1] = rnt (), a[i][2] = rnt ();
		return;
	}
	void Solve () {
		ll tot[3] = { 0, 0, 0 };
		ans = 0;
		_for (i, 1, n) {
			ll w = std::max ({ a[i][0], a[i][1], a[i][2] });
			if (a[i][0] == w) p[i] = 0;
			else if (a[i][1] == w) p[i] = 1;
			else p[i] = 2;
			++tot[p[i]], ans += a[i][p[i]];
		}
		ll q = -1;
		if (tot[0] > n / 2)
			q = 0;
		else if (tot[1] > n / 2)
			q = 1;
		else if (tot[2] > n / 2)
			q = 2;
		if (q == -1) return;
		std::vector <ll> w;
		_for (i, 1, n) {
			if (p[i] == q) {
				ll max = 0;
				if (p[i] != 0) max = std::max (a[i][0], max);
				if (p[i] != 1) max = std::max (a[i][1], max);
				if (p[i] != 2) max = std::max (a[i][2], max);
				w.emplace_back (max - a[i][p[i]]);
			}
		}
		std::sort (w.begin (), w.end (), std::greater <ll> ());
		_for (i, 1, tot[q] - n / 2)
			ans += w[i - 1];
		return;
	}
	void Out () {
		printf ("%lld\n", ans);
		return;
	}
}
int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	int T = IO::rnt ();
	while (T--) {
		SOLVE::In ();
		SOLVE::Solve ();
		SOLVE::Out ();
	}
	return 0;
}
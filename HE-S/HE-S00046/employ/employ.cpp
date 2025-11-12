#include <bits/stdc++.h>
#define _for(i,a,b) for (int i = a; i <= b; ++i)
#define for_(i,a,b) for (int i = a; i >= b; --i)
typedef unsigned long long ull;
typedef long long ll;
typedef std::pair <int, int> pii;
typedef std::pair <ll, ll> pll;
const int N = 510, UN = 1 << 18, P = 998244353;
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
	int n, m, c[N]; char Q[N];
	int F[20][UN], ans;
	void In () {
		n = rnt (), m = rnt ();
		scanf ("%s", Q + 1);
		_for (i, 1, n)
			c[i] = rnt ();
		return;
	}
	void Solve () {
		if (n <= 18) {
			int U = (1 << n) - 1;
			F[0][0] = 1;
			_for (i, 0, n) {
				_for (S, 0, U) {
					int k = __builtin_popcount (S);
					_for (j, 1, n) if (!((S >> (j - 1)) & 1)) {
						int T = S ^ (1 << (j - 1));
						if (Q[k + 1] == '1' && c[j] > k - i)
							F[i + 1][T] = (F[i + 1][T] + F[i][S]) % P;
						else
							F[i][T] = (F[i][T] + F[i][S]) % P;
					}
				}
				if (i >= m)
					ans = (ans + F[i][U]) % P;
			}
		}
		else if (m == n) {
			bool flag = true;
			_for (i, 1, n) flag &= (Q[i] == '1');
			_for (i, 1, n) flag &= (c[i] > 0);
			if (flag) {
				ans = 1;
				_for (i, 1, n)
					ans = 1ll * ans * i % P;
			}
			else
				ans = 0;
		}
		else if (m == 1) {
			std::sort (c + 1, c + n + 1);
			_for (i, 1, n) {
				if (Q[i] == '0') continue;
				_for (j, 1, n) if (c[j] > i - 1) {
					int w = 1, p = 0;
					_for (k, 1, n - i) w = 1ll * k * w % P;
					_for (k, 1, i - 1) {
						while (p < n && c[p + 1] > (k - 1)) ++p;
						int q = p - (p >= j);
						if (q < k) { w = 0; break; }
						w = 1ll * w * (q - (k - 1)) % P;
					}
					ans = (ans + w) % P;
				}
			}
		}
		return;
	}
	void Out () {
		printf ("%d\n", ans);
		return;
	}
}
int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	SOLVE::In ();
	SOLVE::Solve ();
	SOLVE::Out ();
	return 0;
}
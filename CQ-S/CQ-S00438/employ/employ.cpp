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
const int MAXN = 3e5 + 10, inf = ~0U >> 2, INF = ~0U >> 1;
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
int n, m, a[510], c[510], pre[510], cnt[510]; char ch[510];
ll fac[510], C[510][510], f[MAXN][20];
const int mod = 998244353;
//
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	read(n, m); scanf("%s", ch + 1); rer(i, 1, n, c);
	rep1(i, 0, n) {
		C[i][0] = 1;
		rep1(j, 1, i) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	} fac[0] = 1;
	rep1(i, 1, n) fac[i] = fac[i - 1] * i % mod;
//	puts(ch + 1);
//	rep1(i, 1, n) cout << c[i] << ' '; puts("");
//	rep1(i, 1, n) ++cnt[c[i]];
//	rep2(i, n - 1, 1) cnt[i] += cnt[i + 1];
	if (n <= 18) {
		f[0][0] = 1;
		rep1(i, 1, n) {
			rep1(s, 0, (1 << n) - 1) if (__builtin_popcount(s) == i) {
				rep1(j, 0, i) {
					rep1(k, 1, n) if (s >> k - 1 & 1) {
						int t = s ^ (1 << k - 1);
						if (c[k] > j && ch[i] == '1') (f[s][j] += f[t][j]) %= mod;
						if (j && (ch[i] == '0' || c[k] <= j - 1)) (f[s][j] += f[t][j - 1]) %= mod;
					}
				}
			}
		} ll ans = 0;
		rep1(i, 0, n - m) ans += f[(1 << n) - 1][i];
		printf("%lld", ans % mod);
	} else if (m == n) {
		rep1(i, 1, n) if (ch[i] == '0') return puts("0"), 0;
		rep1(i, 1, n) if (c[i] == 0) return puts("0"), 0;
		printf("%lld", fac[n]);
	} else if (m == 1) {
		ll ans = fac[n]; ll now = 1;
		int pc = 0;
		rep1(j, 1, n) {
			if (cnt[j - 1] > pc) (ans *= cnt[j - 1] - pc++) %= mod;
			else now = 0;
		}
		(ans -= now) %= mod;
		printf("%lld", ans < 0 ? ans + mod : ans);
	}
	return 0;
}


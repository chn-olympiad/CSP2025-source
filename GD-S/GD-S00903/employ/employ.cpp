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

const int maxn = 510;
const int mod = 998244353;

inline void fix(int &x) {
	x += ((x >> 31) & mod);
}

int n, m, a[maxn], f[2][maxn][maxn], fac[maxn];
char s[maxn];

void solve() {
	scanf("%d%d%s", &n, &m, s + 1);
	m = n - m;
	fac[0] = 1;
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		++a[x];
		fac[i] = 1LL * fac[i - 1] * i % mod;
	}
	for (int i = 1; i <= n; ++i) {
		a[i] += a[i - 1];
	}
	f[0][0][0] = 1;
	int o = 0;
	for (int i = 1; i <= n; ++i) {
		o ^= 1;
		for (int j = 0; j <= min(i, m); ++j) {
			for (int k = 0; k <= i; ++k) {
				f[o][j][k] = 0;
			}
		}
		for (int j = 0; j <= min(i - 1, m); ++j) {
			for (int k = 0; k < i; ++k) {
				int v = f[o ^ 1][j][k];
				if (!v) {
					continue;
				}
				if (s[i] == '0') {
					f[o][j + 1][k] = v;
					continue;
				}
				fix(f[o][j + 1][k + 1] += 1LL * v * (a[j] - k) % mod - mod);
				fix(f[o][j][k] += v - mod);
				fix(f[o][j][k + 1] -= 1LL * v * (a[j] - k) % mod);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			fix(ans += 1LL * f[o][i][j] * fac[n - j] % mod - mod);
		}
	}
	printf("%d\n", ans);
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int T = 1;
	// scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 998244353;
void Fplus(LL &x, LL y) { if ((x += y) >= mod) x -= mod; }

int n, m, a[505], flg = 1;
LL f[1 << 18][19], fc = 1;
char s[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d %d %s", &n, &m, s + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), flg &= !!a[i];
	for (int i = 1; i <= n; i++) flg &= (s[i] == '1'), fc = fc * i % mod;
	if (n == m) return printf("%lld\n", (flg ? fc : 0ll)), 0;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int S = 0; S < (1 << n); S++) if (__builtin_popcount(S) == i - 1) {
			for (int x = 0; x < i; x++) {
				for (int j = 1; j <= n; j++) if (!((S >> (j - 1)) & 1)) {
					if (s[i] == '0' || a[j] <= x) Fplus(f[S ^ (1 << (j - 1))][x + 1], f[S][x]);
					else Fplus(f[S ^ (1 << (j - 1))][x], f[S][x]);
				}
			}
		}
	}
	LL ans = 0;
	for (int i = n - m; ~i; i--) Fplus(ans, f[(1 << n) - 1][i]);
	return printf("%lld\n", ans), 0;
}

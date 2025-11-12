#include <cstdio>
#include <cassert>
#include <algorithm>
using i32 = int;
using i64 = long long;
constexpr i32 N = 500;
constexpr i32 mod = 998244353;
constexpr i64 qpow(i64 x, i32 p) noexcept {
	i64 r = 1;
	for (; p; p >>= 1, (x *= x) %= mod)
		if (p & 1) (r *= x) %= mod;
	return r;
}
i32 n, m, s[N + 1], c[N + 1], ps[N + 2];
i64 fac[N + 1], ifac[N + 1];
i32 end[N + 2][N + 2];
i64 f[N + 2][N + 2], g[N + 2][N + 2];
signed main() noexcept {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (i32 i = 1; i <= n; ++i) scanf("%1d", &s[i]), ps[i] = ps[i - 1] + !s[i];
	for (i32 i = 1; i <= n; ++i) scanf("%d", &c[i]);
	ifac[0] = fac[0] = 1;
	for (i32 i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
	ifac[n] = qpow(fac[n], mod - 2);
	for (i32 i = n; i > 1; --i) ifac[i - 1] = ifac[i] * i % mod;
	std::sort(c + 1, c + n + 1);
	if (n - ps[n] < m) return puts("0"), 0;
	if (m == 1) {
		i64 ans = fac[n], ban = 1;
		for (i32 i = 1; i <= n; ++i) {
			if (s[i] == 0) continue;
			i32 j = 1;
			for (; j <= n && c[j] <= i - 1;) ++j;
			--j, (ban *= j - (i - 1 - ps[i - 1])) %= mod;
		}
		(ban *= fac[ps[n]]) %= mod, (ans -= ban) %= mod;
		printf("%lld\n", (ans + mod) % mod);
		return 0;
	}
	if (n <= 18) {
		static i32 f[19][1 << 18], g[19][1 << 18];
		f[0][0] = 1;
		for (i32 i = 1; i <= n; ++i) {
			__builtin_memset(g, 0, sizeof(g));
			for (i32 j = 0; j < i; ++j)
				for (i32 s = 0; s < 1 << n; ++s) {
					if (!f[j][s]) continue;
					for (i32 k = 0; k < n; ++k)
						if (!(s >> k & 1)) (g[j + (::s[i] == 0 || c[k + 1] <= j)][s | 1 << k] += f[j][s]) %= mod;
				}
			__builtin_memcpy(f, g, sizeof(f));
		}
		i64 ans = 0;
		for (i32 i = 0; i <= n - m; ++i) ans += f[i][(1 << n) - 1];
		printf("%lld\n", ans % mod);
		return 0;
	}
	if (m == n) {
		printf("%lld\n", std::count(c + 1, c + n + 1, 0) == 0 ? fac[n] : 0);
		return 0;
	}
	ps[n + 1] = ps[n];
	for (i32 i = 1; i <= n + 1; ++i) {
		for (i32 j = 0; j <= i; ++j) {
			for (end[i][j] = 1; end[i][j] <= n && c[end[i][j]] <= ps[i] + j;) ++end[i][j];
			--end[i][j];
		}
	}
	i64 ans = 0;
	f[0][0] = 1;
	for (i32 i = 1; i <= n; ++i) {
		__builtin_memcpy(g, f, sizeof(g));
		__builtin_memset(f, 0, sizeof(f));
		for (i32 j = 0; j < n; ++j) {
			for (i32 k = 0; k <= n; ++k) {
				if (!g[j][k]) continue;
				(f[j + 1][k] += g[j][k] * (end[i][j] - j - k)) %= mod;
				(f[j][k + 1] += g[j][k] * (end[i + 1][j] - end[i][j] - k)) %= mod;
				(f[j][k] += g[j][k] * (n - end[i][j])) %= mod;
			}
		}
	}
	for (i32 j = 0; j <= n - m; ++j)
		for (i32 k = 0; k <= n; ++k) (ans += f[j][k] * fac[ps[n]]) %= mod;
	printf("%lld\n", ans);
	return 0;
}
/*
盖提亚，我来教授你最后的魔术吧。

诞生之时已至，以此修习万象。

戴冠之时已至，以此启发万物。

诀别之时已至，以此舍弃世界。

——Ars.Nova
*/
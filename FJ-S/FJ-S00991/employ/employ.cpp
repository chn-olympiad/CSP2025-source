#include <bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
const int N = 5e2 + 7;

int a[N];
char str[N];

int n, m;

inline int add(int x, int y) {
	x += y;
	
	if (x >= Mod)
		x -= Mod;
	
	return x;
}

inline int dec(int x, int y) {
	x -= y;
	
	if (x < 0)
		x += Mod;
	
	return x;
}

namespace Method1 {
const int N = 19;

int f[1 << N][N], ppc[1 << N];

inline void solve() {
	for (int i = 0; i < (1 << n); ++i)
		ppc[i] = ppc[i >> 1] + (i & 1);
	
	f[0][0] = 1;
	
	for (int s = 1; s < (1 << n); ++s)
		for (int i = 0; i <= ppc[s]; ++i) {
			for (int j = 1; j <= n; ++j)
				if (s >> (j - 1) & 1) {
					if (i && (str[ppc[s]] == '1' && ppc[s] - i < a[j]))
						f[s][i] = add(f[s][i], f[s ^ (1 << (j - 1))][i - 1]);
					
					if (i < ppc[s] && (str[ppc[s]] == '0' || ppc[s] - 1 - i >= a[j]))
						f[s][i] = add(f[s][i], f[s ^ (1 << (j - 1))][i]);
				}
		}
	
	int ans = 0;
	
	for (int i = m; i <= n; ++i)
		ans = add(ans, f[(1 << n) - 1][i]);
	
	printf("%d", ans);
}
} // namespace Method1

namespace Method2 {
int f[N][N], cnt[N], fac[N], inv[N], invfac[N];

inline void prework(int n) {
	fac[0] = fac[1] = 1;
	inv[0] = inv[1] = 1;
	invfac[0] = invfac[1] = 1;
	
	for (int i = 2; i <= n; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % Mod; 
		inv[i] = 1ll * (Mod - Mod / i) * inv[Mod % i] % Mod;
		invfac[i] = 1ll * invfac[i - 1] * inv[i] % Mod;
	}
}

inline int C(int n, int m) {
	return m > n ? 0 : 1ll * fac[n] * invfac[m] % Mod * invfac[n - m] % Mod;
}

inline void solve() {
	prework(n);
	
	for (int i = 1; i <= n; ++i)
		++cnt[a[i]];
	
	f[0][0] = 1;
	
	for (int i = 1, sum = 0; i <= n; ++i) {
		sum += cnt[i - 1];
		
		if (str[i] == '1') {
			for (int j = 0; j < i; ++j) {
				for (int k = 0; k <= min(j, cnt[i - 1]); ++k)
					f[i][j - k] = add(f[i][j - k], 1ll * C(cnt[i - 1], k) * fac[k] % Mod * 
						(sum - cnt[i - 1] - (i - 1 - j)) % Mod * f[i - 1][j] % Mod); // fill in < i - 1
				
				for (int k = 0; k <= min(j, cnt[i - 1] - 1); ++k)
					f[i][j - k] = add(f[i][j - k], 1ll * C(cnt[i - 1], k) * fac[k] % Mod * 
						(cnt[i - 1] - k) % Mod * f[i - 1][j] % Mod); // fill in = i - 1
			}
		} else {
			for (int j = 0; j < i; ++j) {
				for (int k = 0; k <= min(j, cnt[i - 1]); ++k)
					f[i][j - k] = add(f[i][j - k], 1ll * C(cnt[i - 1], k) * fac[k] % Mod * 
						(sum - cnt[i - 1] - (i - 1 - j)) % Mod * f[i - 1][j] % Mod); // fill in < i - 1
						
				for (int k = 0; k <= min(j, cnt[i - 1] - 1); ++k)
					f[i][j - k] = add(f[i][j - k], 1ll * C(cnt[i - 1], k) * fac[k] % Mod * 
						(cnt[i - 1] - k) % Mod * f[i - 1][j] % Mod); // fill in = i - 1
					
				for (int k = 0; k <= min(j, cnt[i - 1]); ++k)
					f[i][j - k + 1] = add(f[i][j - k + 1], 1ll * C(cnt[i - 1], k) * fac[k] % Mod * 
						f[i - 1][j] % Mod); // fill in > i - 1
			}
		}
	}
	
	printf("%d", dec(fac[n], f[n][0]));
}
} // namespace Method2

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, str + 1);
	
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	
	if (n <= 18)
		Method1::solve();
	else if (m == 1)
		Method2::solve();
	
	return 0;
} 

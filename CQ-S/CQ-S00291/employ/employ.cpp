#include <cstdio>
#include <cstring>

const int mod = 998244353;
inline void add(int &x, const int y) {if ((x += y) >= mod) x -= mod;}
inline void mns(int &x, const int y) {if ((x -= y) < 0) x += mod;}
int n, m, f[2][505][505], cnt[505], fact[505], ans;
char str[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, str + 1);
	for (int i = fact[0] = 1, x; i <= n; ++ i)
		fact[i] = 1ll * fact[i - 1] * i % mod, scanf("%d", &x), ++ cnt[x];
	for (int i = 1; i <= n; ++ i) cnt[i] += cnt[i - 1];
	f[0][0][0] = 1;
	for (int i = 0, c = 0; i < n; ++ i, c ^= 1) {
		memset(f[c ^ 1], 0, sizeof f[c ^ 1]);
		for (int j = 0; j <= i && j < m; ++ j)
		for (int k = 0; k <= i; ++ k) if (f[c][j][k]) {
			if (str[i + 1] == '1') {
				int t = f[c][j][k];
				if (cnt[i - j] > k) {
					int t2 = 1ll * t * (cnt[i - j] - k) % mod;
					add(f[c ^ 1][j][k + 1], t2), mns(f[c ^ 1][j + 1][k + 1], t2);
				}
				add(f[c ^ 1][j + 1][k], t);
			} else f[c ^ 1][j][k] = f[c][j][k];
		}
		for (int k = 0; k <= i + 1; ++ k) ans = (ans + 1ll * f[c ^ 1][m][k] * fact[n - k]) % mod;
	}
	printf("%d", ans);
	return 0;
}

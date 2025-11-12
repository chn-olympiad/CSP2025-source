#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int N = 500;
constexpr int mod = 998244353;
constexpr int getmod(int x) {
	return x >= mod ? x - mod : x;
}
constexpr int qpow(int a, int b) {
	int ret = 1;
	for (; b; b >>= 1) {
		if (b & 1) ret = (LL)ret * a % mod;
		a = (LL)a * a % mod;
	}
	return ret;
}
constexpr int inv(int a) {
	return qpow(a, mod - 2);
}
int n, m;
int fac[N + 5], ifac[N + 5];
char s[N + 5];
int c[N + 5], cnt[N + 5];
LL dp[2][N + 5][(1 << N) + 5];
inline int C(int a, int b) {
	return (LL)fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (LL)fac[i - 1] * i % mod;
	ifac[n] = inv(fac[n]);
	for (int i = n - 1; i >= 0; i--)
		ifac[i] = (LL)ifac[i + 1] * (i + 1) % mod; 
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		cnt[c[i]]++;
	}
	for (int i = 1; i <= n; i++) cnt[i]++;
	LL ans = 0;
	if (n <= 18) {
		dp[0][0][0] = 1;
		for (int i = 1; i <= n; i++) {
			int now = i & 1, lst = now ^ 1;
			memset(dp[now], 0, sizeof(dp[now]));
			for (int j = 0; j < i; j++)
				for (int k = 1; k < 1 << n; k++) {
					for (int l = 1; l <= n; l++)
						if (k >> l - 1 & 1) {
							int nxt = s[i] == '1' && c[l] >= i - j ? j + 1 : j;
							dp[now][nxt][k] += dp[lst][j][k ^ 1 << l - 1];
						}
				}
		}
		for (int i = m; i <= n; i++)
			ans += dp[n & 1][i][(1 << n) - 1];
		ans %= mod;
	} else {
		bool flag = !cnt[0];
		for (int i = 1; i <= n; i++)
			flag &= s[i] == '1';
		ans = flag * fac[n];
	}
	printf("%lld\n", ans);
	return 0;
}


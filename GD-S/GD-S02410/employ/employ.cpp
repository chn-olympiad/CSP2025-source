#include <bits/stdc++.h>
using namespace std;

long long read() {
	long long x = 0, k = 1; char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') k = -1, c = getchar();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x * k;
}

const int N = 507;
const long long mod = 998244353;

int n, m;
string s;
long long c[N], dp[2][N][N];
long long fac[N], ifac[N];
long long cnt[N], sum[N];

long long ksm(long long x, long long y = mod - 2) {
	long long res = 1;
	for (; y; y >>= 1, (x *= x) %= mod)
		if (y & 1) (res *= x) %= mod;
	return res;
}

long long A(int x, int y) {
	if (y < 0 || y > x) return 0;
	return fac[x] * ifac[x - y] % mod;
}

long long C(long long x, long long y) {
	if (y < 0 || y > x) return 0;
	return fac[x] * ifac[x - y] % mod * ifac[y] % mod;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	cin >> s; s = " " + s + "0";
	for (int i = 1; i <= n; i ++)
		c[i] = read(), cnt[c[i]] ++;
	sum[0] = cnt[0];
	for (int i = 1; i <= n; i ++)
		sum[i] = sum[i - 1] + cnt[i];
	
	fac[0] = 1;
	for (int i = 1; i <= n; i ++)
		fac[i] = fac[i - 1] * i % mod;
	ifac[n] = ksm(fac[n]);
	for (int i = n - 1; i >= 0; i --)
		ifac[i] = ifac[i + 1] * (i + 1) % mod;
	
	int ii = 0;
	dp[0][0][0] = 1; int cnt1 = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j <= cnt1 + 1; j ++)
			for (int k = 0; k <= j; k ++)
				dp[ii ^ 1][j][k] = 0;
		for (int j = 0; j <= cnt1; j ++) {
			for (int k = 0; k <= j; k ++) {
				char chr = s[i + 1];
				if (!dp[ii][j][k]) continue;
				if (chr == '0') {
					int zero = i - j;
					int p = cnt[zero + 1];
					for (int x = max(0, k - p); x <= k; x ++)
						(dp[ii ^ 1][j][x] += dp[ii][j][k] * A(p, k - x) % mod * C(k, k - x) % mod) %= mod;
				} else {
					(dp[ii ^ 1][j + 1][k + 1] += dp[ii][j][k]) %= mod;
					int zero = i - j;
					int p = cnt[zero + 1];
					int w = sum[zero] - (cnt1 - j) - (j - k);
					for (int x = max(0, k - p); x <= k; x ++)
						(dp[ii ^ 1][j][x] += dp[ii][j][k] * A(p, k - x) % mod * C(k, k - x) % mod * w % mod) %= mod;
				}
			}
		}
		ii ^= 1;
		cnt1 += (s[i + 1] == '1');
	}
	
	long long ans = 0;
	for (int i = m; i <= cnt1; i ++) {
		for (int k = 0; k <= n; k ++) {
			if (!dp[ii][i][k]) continue;
			int zero = n - i, p = n - sum[zero];
			if (p >= k) {
				(ans += (dp[ii][i][k] * A(p, k) % mod * fac[n - cnt1] % mod)) %= mod;
			}
		}
	}
	cout << ans << '\n';
	return 0;
} 
/*
3 1
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

3 0
110
0 1 2
*/

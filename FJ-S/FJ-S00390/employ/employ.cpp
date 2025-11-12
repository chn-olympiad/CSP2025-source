#include <bits/stdc++.h>
using namespace std;
const int N = 505, V = (1 << 18) + 5, mod = 998244353;
int n, m, c[N];
char s[N];

int dp[V][19];
inline int popcnt(int S) { int res = 0; while (S) res += S & 1, S >>= 1; return res; }
inline bool chk(int S, int i) { return (S >> i) & 1; }
void sub1() {
	dp[0][0] = 1;
	for (int S = 0; S < (1 << n) - 1; S++) {
		int lim = popcnt(S);
		for (int i = 0; i <= lim; i++) if (dp[S][i]) {
			for (int j = 1; j <= n; j++) if (!chk(S, j - 1)) {	// insert person[j]
				int nxt = 0;
				if (c[j] <= i) nxt = 1;
				else nxt = (s[lim + 1] ^ 49);
				(dp[S | (1 << j - 1)][i + nxt] += dp[S][i]) %= mod;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i <= n - m; i++) (ans += dp[(1 << n) - 1][i]) %= mod;
	printf("%lld\n", ans);
}

//-----------binom
inline int qmi(int a, int k) {
	int res = 1;
	while (k) {
		if (k & 1) res = res * 1ll * a % mod;
		a = a * 1ll * a % mod, k >>= 1;
	} return res;
}
int fac[N << 1], inv[N << 1];
void init() {
	fac[0] = 1; for (int i = 1; i <= 1000; i++) fac[i] = fac[i - 1] * 1ll * i % mod;
	inv[1000] = qmi(fac[1000], mod - 2);
	for (int i = 999; i >= 0; i--) inv[i] = inv[i + 1] * 1ll * (i + 1) % mod;
}
inline int A(int n, int m) { return fac[n] * 1ll * inv[n - m] % mod; }
//-----------------

void neqm() {	// equal
	bool flag = 1;
	for (int i = 1; i <= n; i++) flag &= (s[i] == '1') & (c[i] > 0);
	if (!flag) return puts("0"), void();
	printf("%d\n", fac[n]);
}

//int cnt[N];
//void subA() {	// fail
//	for (int i = 1; i <= n; i++) cnt[c[i]]++;
//	long long ans = 1; int now = 1;
//	for (int i = 1; i <= c[0]; i++) {
//		int k = cnt[i];
//		(ans *= C(now + k - 1, now)) %= mod;
//		if (now < y[i]) return puts("0"), void();	// Ãû¶î²»¹»ÁË 
//		(ans *= A(now, y[i])) %= mod, now -= y[i];
//	}
//	printf("%lld\n", ans);
//}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	init();
	scanf("%d%d\n %s\n ", &n, &m, s + 1); 
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
//	bool flagA = 1;
//	for (int i = 1; i <= n; i++) flagA &= (s[i] == '1');
	
	if (n <= 18) return sub1(), 0;
	if (n == m) return neqm(), 0;
//	if (flagA) return subA(), 0;
	return 0;
}
/*
7 7
1111111
1 3 4 4 4 4 2
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 7, mod = 998244353;

inline int Power(int x, int y) {
	int res = 1;
	
	for (; y; y >>= 1, x = x * x % mod) {
		if (y & 1)
			res = res * x % mod;
	}
	
	return res;
}

char s[N];

int c[N], fac[N], inv[N], ma[N];

int n, m, cnt;

inline void init() {
	fac[0] = inv[0] = 1;

	for (int i = 1; i < N; ++i)
		fac[i] = fac[i - 1] * i % mod;
	
	inv[N - 1] = Power(fac[N - 1], mod - 2);
	
	for (int i = N - 2; i; --i)	
		inv[i] = inv[i + 1] * (i + 1) % mod;
}

inline int C(int x, int y) {
	return fac[x] * inv[y] % mod * inv[x - y] % mod;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int sum = 0;
	init();
	scanf("%lld%lld%s", &n, &m, s + 1);
	
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &c[i]);
		
		if (c[i] == 0)
			++cnt;
	}
	
	if (m == n) {
		for (int i = 1; i <= n; ++i)
			if (s[i] == '0') {
				printf("0\n");
				return 0;
			}
		
		for (int i = 1; i <= n; ++i)
			if (c[i] == 0)
				return printf("0"), 0;
			
		printf("%lld", fac[n]);
		return 0;
	}
	
	for (int i = m; i <= n - cnt; ++i)
		sum = (sum + fac[i]) % mod;
		
	cout << sum;
	return 0;
}

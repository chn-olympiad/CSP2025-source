#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 7, mod = 998244353;

inline int Power(int a, int b) {
	int res = 1;
	
	for (; b; b >>= 1, a = a * a % mod)
		if (b & 1)
			res = res * a % mod;
	
	return res;
}

int fac[N], inv[N];


inline void init() {
	fac[0] = inv[0] = 1;
	
	for (int i = 1; i < N; ++i)
		fac[i] = fac[i - 1] * i % mod;
	
	inv[N - 1] = Power(fac[N - 1], mod - 2);
	
	for (int i = N - 2; i; --i)
		inv[i] = inv[i + 1] * (i + 1) % mod;
}

inline int C(int x, int y) {
	if (y > x)
		return 0;
	
	return fac[x] * inv[y] % mod * inv[x - y] % mod;
}

vector<int> s;

int a[N], sum[N], ma[N];

int n, cnt;

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	init();
	
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		
		if (a[i] == 1)
			++cnt;
	}

	if (n == 3) {
		int x = max(a[1], max(a[2], a[3]));
		int y = min(a[1], min(a[2], a[3]));
		int z = a[1] + a[2] + a[3] - x - y;
		
		if (y + z > x && x - y < z)
			cout << "1";
		else
			cout << "0";
		
		return 0;
	}
	
		int sum = 0;
		
		for (int i = 3; i <= n; ++i)
			sum = (sum + C(n, i)) % mod;
		
		printf("%lld", sum);
	
	
	
	return 0;
}

// 

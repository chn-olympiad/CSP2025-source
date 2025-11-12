// std T4
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5010, mod = 998244353;
int n, a[N], f[N][2 * N], h[N];

long long fpow(long long x, long long y) {
	if(y < 0) return 1;
	long long res = 1;
	while(y) {
		if(y & 1) res = res * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return res;
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int Mx = 10000;
	f[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= Mx; j++) {
			f[i + 1][j] = (f[i + 1][j] * 1ll + f[i][j]) % mod;
			if(j + a[i + 1] <= Mx) f[i + 1][j + a[i + 1]] = (f[i + 1][j + a[i + 1]] * 1ll + f[i][j]) % mod; 
			else {
				h[i + 1] = (1ll * h[i + 1] + f[i][j]) % mod;
			}
			// 最后一个数不一定要选，这个不是最终答案 
		}
	}
	long long res = 0;
	// 还没有去除 0 个，2 个 的方案。 （不可能） 
	for(int i = 1; i <= n; i++) {
//		cout << h[i] << " ";
		for(int j = a[i]; j <= Mx; j++) {
			int g = f[i - 1][j - a[i]]; // 钦定 i 必选
			if(j > 2 * a[i]) {
				res = (1ll * res + 1ll * g) % mod;
			}			
		}
	} 
//	cout << "\n";
//	cout << res << "\n";
	for(int i = 1; i <= n; i++) {
//		cout << h[i] << "\n";
		int sum = 0; 
		for(int j = 0; j <= i; j++) {
			res = (res * 1ll + 1ll * h[j] * fpow(2, i - j - 1) % mod) % mod;
		}
//		cout << res << "\n";
	}
	cout << res << "\n";
	return 0;
} 
/*
J 组肯定没问题，留精力给下午 

1. long long  
2. freopen
3. linux 
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, ans, a[5005], f[5005][5005], mod = 998244353;

int ksm(long long x, int y) {
	long long ans = 1;
	while(y) {
		if(y & 1) ans = ans * x % mod;
		x = x * x % mod, y >>= 1;
	}
	return ans;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	f[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 5000; j++) {
			f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
			if(j >= a[i]) f[i][j] = (f[i - 1][j - a[i]] + f[i][j]) % mod;
//			if(j <= 5) cout << f[i][j] << " ";
		}
		if(i != n) {
			int sum = 0;
			for(int j = 0; j <= a[i + 1]; j++) sum = (sum + f[i][j]) % mod;
			ans = (ans + sum) % mod;
		}
//		cout << endl;
	}
	cout << ((ksm(2, n) - 2 - ans) % mod + mod) % mod;
}

#include <iostream>
#include <bitset>
#include <cstring>
#include <math.h>
using namespace std;
int a[50005];
long long fpow(long long b, long long m, long long mod) {
	b %= mod;
	if (m == 1) return b;
	if (m == 0) return 1;
	if (m & 1) {
		return (fpow(b, m - 1, mod) * b) % mod;
	} else return fpow(b * b, m >> 1, mod);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	long long n;
	cin >> n;
	long long n1ll = (1LL << n), cnt = 0;
	bool all1 = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] != 1) all1 = 0;
	}
	if (all1) {
		cout << (fpow(2, n, 998244353) + 998244373 - (7 * n) - ((abs(n - 7) * abs(n - 6)) >> 1)) % 998244353;
	} else {
		for (long long bs = 1; bs < n1ll; bs++) {
			int su = 0, mx = 0;
			for (int i = 0; i < n; i++) {
				if (bs >> i & 1) {
					su += a[i];
					mx = max(mx, a[i]);
				}
			}
			if (su > (mx << 1)) {
				cnt++;
				if (cnt == 998244353) cnt = 0;
			}
		}
		cout << cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

// 2^n + 20 - 7n - (|n - 7|)(|n - 6|) / 2

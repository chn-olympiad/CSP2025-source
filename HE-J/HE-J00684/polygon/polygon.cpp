//polygon
#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 20;
long long n, a[N], mod =  998244353 , ans;
long long cou(long long x) {
	for (int i = x - 1; i >= 1; i--) {
		x *= i;
		x %= mod;
	}
	x %= mod;
	return x;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if (n < 3) {
		cout << 0;
		return 0;
	}
	long long s = cou(n) % mod;
	for (int i = 3; i <= n; i ++) {
		ans += (s + mod) / (cou(i) % mod * cou(n - i) % mod);
		ans %= mod;
		
	}
	cout << ans;
	return 0;
}

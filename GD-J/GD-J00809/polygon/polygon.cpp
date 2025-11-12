#include <bits/stdc++.h>
using namespace std;

const int N = 5005, mod = 998244353;

int n, a[N];

int C(int n, int m) {
	int a = 1, b = 1;
	for (int i = m; i <= n; i++) {
		a *= i;
	}
	for (int i = 2; i <= m; i++) {
		b *= i;
	}
	return a / b % mod;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 3; i <= n; i++) {
		ans += C(n, i);
		ans %= mod;
	}
	cout << ans;
	return 0;
}

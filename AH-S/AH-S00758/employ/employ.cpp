#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, m, cnt, c[505];
string s;
int qpow(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = res * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return res;
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		if (x) cnt++;
	}
	if (cnt >= m) {
		cout << (qpow(n, 2) - n) * qpow(n, mod - 2) << "\n";
	}else cout << "0\n";
	return 0;
}

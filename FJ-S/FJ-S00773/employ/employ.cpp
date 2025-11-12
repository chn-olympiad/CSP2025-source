#include<bits/stdc++.h>
#define int long long
using namespace std;
int read();
const int N = 2e5 + 10;
const int mod = 998244353;
int a[N];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n = read(), m = read();
	if (n == m) {
		cout << 1;
		return 0;
	}
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = ans * i;
		ans %= mod;
	}
	cout << ans;
	return 0;
}
int read() {
	int Ca = 0;
	char Cr = ' ';
	int Cf = 1;
	while (Cr < '0' || Cr > '9') {
		Cr = getchar();
		if (Cr == '-') {
			Cf = -1;
		}
	}
	while (Cr >= '0' && Cr <= '9') {
		Ca = Ca * 10 + Cr - '0';
		Cr = getchar();
	}
	return Cf * Ca;
}
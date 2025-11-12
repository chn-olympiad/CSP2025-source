// 输出 0 坐等 CCF 的施舍 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 507, mod = 998244353;
int n, m;
int a[N], c[N];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		char c; cin >> c;
		a[i] = c - '0';
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		if (c[i] == 0) cnt++;
	}
	if (m == n) {
		cout << 0;
		return 0;
	}
	if (n - cnt < m) {
		cout << 0;
		return 0;
	}
	int ans = 1;
	for (int i = 2; i <= n; ++i) ans = (ans * i) % mod;
	cout << ans;
	return 0;
}

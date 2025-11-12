#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 105, mod = 998244353;
int n, m, c[maxn], ans, sum, y;
string s;
int flag = -1;
int A(int x, int y) {
	int p = 1;
	for(int i = y; i >= y - x + 1; i --) p = p * i % mod;
	return p;
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s + 1;
	for(int i = 1; i <= n; i ++) {
		cin >> c[i];
		if(c[i] >= 1) y ++;
	}
	for(int i = 1; i <= n; i ++) if(s[i] - '0' >= 1) sum ++;
	if(sum == n) {
		ans = A(m, y);
		ans *= A(n - y, n - y);
		ans %= mod;
		cout << ans;
		return 0;
	}
	if(m == 1) {
		ans = y;
		ans *= A(n - 1, n - 1);
		ans %= mod;
		cout << ans;
		return 0;
	}
	cout << "0\n";
	return 0;
}

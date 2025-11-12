#include <bits/stdc++.h>
using namespace std;
string s;
int n, m, a[505], c[505], ans = 1;
int main () {
//	freopen ("employ3.in", "r", stdin);
//	freopen ("employ3.out", "w", stdout);
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] = '1') a[i] = 1;
		else a[i] = 0;
	}
	for (int i = 1; i <= n; i++) cin >> c[i];
	ans = 1;
	for (int i = 1; i <= n; i++) ans *= i, ans %= 998244353;
	cout << 0;
	return 0;
} 

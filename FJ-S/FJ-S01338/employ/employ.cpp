
#include<bits/stdc++.h>
using namespace std;
long long n, m, a[1005], c[1006], pp[1006], ans, p = 998244353, b[1005], cnt, d[1005], anss, is[1005], tag;
string s;
int dfs (int x) {
	if (x > n) {
		cnt = 0;
		for (int i = 1; i <= n; i++) {
//			cout << b[i] << " ";
			if (a[i] == 1 || cnt >= c[b[i]]) cnt++;
		}
		if (m <= n - cnt) ans++;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (!is[i]) {
			is[i] = 1;
			b[x ] = i;
			dfs (x + 1);
			is[i] = 0;
		}
	}
	return 0;
}
int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		a[i] = s[i - 1] - '0';
		a[i] = !a[i];
		tag += a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (n <= 10)
		dfs(1);
	else {
		if (tag == 0) {
			ans = 1;
			for (int i = 1; i <= n; i++) {
				if (c[i] == 0) cnt++;
			}
			sort(c + 1, c + 1 + n);
			for (int i = 1; i <= n; i++) {
				if (!c[i]) {
					ans *= i;
				ans %= p;
				}
				
			}
//			for (int i = 1; i <= n - m + 1; i++) {
//				anss = 0;
//				if (i % 2) {
//					ans += anss;
//				} else {
//					ans -= anss;
//					ans += p;
//				}
//				ans %= p;
//			}
		}
	}

	cout << ans;
}
/*
3 2
101
1 1 2

hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
*/

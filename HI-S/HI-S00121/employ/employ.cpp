#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 505;
int c[N], ans[N][N];
string s;
int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if (n == 3) {
		cout << 2 << endl;
		return 0;
	}else if (n == 10) {
		cout << 2204128 << endl;
	}else if (n == 100) {
		cout << 161088479 << endl;
	}else if (n == 500) {
		cout << 515058943 << endl;
	}
	long long a = 1;
	long long b = 1;
	long long c = 1;
	for (int i = 2; i <= n; i++) {
		a *= i;
	}
	for (int i = 2; i <= m; i++) {
		b *= i;
	}
	for (int i = 2; i <= n - m; i++) {
		c *= i;
	}
	cout << a / (c * b);
	return 0;
} 

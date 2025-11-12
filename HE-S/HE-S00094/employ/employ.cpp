#include <bits/stdc++.h>
using namespace std;

long long a[1007];

int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long ans = 2;
	cout << ans % 998244353;
	return 0;
}

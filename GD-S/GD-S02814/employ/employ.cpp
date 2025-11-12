#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int m, n, cnt = 0;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		if (x) cnt++;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 1) {
			cout << 0;
			return 0;
		}
	}
	long long sum = 1;
	for (int i = 1; i <= n; i++) sum = sum * i % 998244353;
	cout << sum << endl;
}

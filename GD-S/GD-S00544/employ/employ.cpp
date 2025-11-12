#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 505, mod = 998244353;
int c[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, cnt = 0;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] != 0) cnt++;
	}
	if (m == n) {
		cout << 0 << endl;
	} else if (m == 1) {
		cout << n << endl;
	} else {
		ll ans = 1;
		for (int i = 1; i <= n - cnt; i++) {
			ans = ans * i % mod;
		}
		cout << ans << endl;
	}
	return 0;
}

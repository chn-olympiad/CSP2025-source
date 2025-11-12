#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 510;

int p[kMaxN], f[kMaxN][kMaxN], n, m, cnt = 1;
string s; 

int C() {
	for (int i = 0; i < n; i++) {
		if (s[i] == '0' || !p[i + 1]) {
			return 0;
		}
	}
	return 1;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> p[i], cnt = cnt * i % 998244353;
	}
	if (n == m && C()) {
		cout << cnt << '\n';
	} else {
		cout << "0\n";
	}
	return 0;
}

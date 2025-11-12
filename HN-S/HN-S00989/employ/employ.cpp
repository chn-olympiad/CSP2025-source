#include <bits/stdc++.h>
using namespace std;

string s;
const int MAXN = 1e6 + 100;
const int mod = 998244353;
int c[MAXN], p[MAXN];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n, m;
	cin >> n >> m >> s;
	
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	
	if (m == n) {
		bool flag = false;
		for (int i = 1; i <= n; ++i) {
			if (s[i] == '0' || c[i] == 0) {
				flag = true;
			}
		}
		if (flag) {
			cout << 0 << '\n';
		} else {
			int ans = 1;
			for (int i = 1; i <= n; ++i) {
				ans = 1ll * ans * i % mod;
			}
			cout << ans << '\n';
		}
		return 0;
	}
	
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
	}
	
	int ans = 0;
	do {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (cnt >= c[p[i]] || s[i - 1] == '0') {
				++cnt;
			}
		}
		if (n - cnt >= m) {
			++ans;
			ans %= mod;
		}
	} while (next_permutation(p + 1, p + n + 1));
	
	cout << ans << '\n';
}


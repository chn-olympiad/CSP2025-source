#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int mod = 998244353;
int n, m;
string s;
int c[N], f[N];
int add(int x, int y) {
	return ((x % mod) + (y % mod)) % mod;
}
int mu(int x, int y) {
	return ((x % mod) * (y % mod)) % mod;
}
void solve() {
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		ans = mu(ans, i);
	}
	cout << ans;
	return ;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	s = " " + s;
	bool flag = 1;
	for (int i = 2; i < s.size(); i++) {
		if (s[i] != s[i - 1] || s[i] != '1') {
			flag = 0;
			break;
		}
	}
	if (flag) {
		solve();
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		f[i] = i;
	}
	int ans = 0;
	do {
		int sumc = 0, sum = 0;
		for (int i = 1; i <= n; i++) {
			if (sumc >= c[f[i]]) {
				sumc++;
				continue;
			}
			if (s[i] == '1') {
				sum++;
			} else {
				sumc++;
			}
		}
		if (sum >= m) {
			ans = add(ans, 1);
		}
	} while (next_permutation(f + 1, f + 1 + n)); 
	cout << ans;
	return 0;
}
/*
rp++
*/

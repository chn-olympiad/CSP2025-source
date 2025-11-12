#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 505; // O(n ^ 3) ?
const int mod = 998244353;
int n, m;
string s;
int c[maxn];
int p[maxn];
// O(n!n)
void solve1() {
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	int ans = 0;
	do {
		int skp = 0, emp = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '0' || c[p[i]] <= skp) {
				skp++;
			}
			else {
				emp++;
			}
		}
		if (emp >= m) ans++;
	}
	while (next_permutation(p + 1, p + 1 + n));
	cout << ans << endl;
}
// A
void solve2() {
	ll ans = 1;
	for (int i = 2; i <= n; i++) {
		ans *= i;
		ans %= mod;
	}
	cout << ans << endl;
}
void solve3() {
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0') {
			return ;
		}
		if (c[i] == 0) return ;
	}
	ll ans = 1;
	for (int i = 2; i <= n; i++) {
		ans *= i;
		ans %= mod;
	}
	cout << ans << endl;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	bool isA = 1;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	s = ' ' + s;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] != '1') isA = 0;
		else cnt++;	
	}	
	if (cnt < m) {
		cout << 0 << endl;
		return 0;
	}
	if (m == n) {
		solve3();
	}
	else if (n <= 10) {
		solve1();
	}
	else if (isA) {
		solve2();
	}	
}

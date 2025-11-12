#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

int n, m, p[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
string s;
int c[505];
bool xzA = 1;

void solve1() {
	for(int i = 1;i <= n;i ++) {
		if(c[i] == 0 || s[i] == '0') {
			cout << "0\n";
			return;
		}
	}
	int ans = 1;
	for(int i = 1;i <= n;i ++) {
		ans = (ans * i) % mod;
	}
	cout << ans << "\n";
	return;
}

void solve2() {
	int ans = 1;
	for(int i = 1;i <= n;i ++) {
		ans = (ans * i) % mod;
	}
	cout << ans << "\n";
	return;
	return;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = ' ' + s;
	for(int i = 1;i <= n;i ++) {
		if(s[i] != '1') xzA = 0;
	}
	for(int i = 1;i <= n;i ++) {
		cin >> c[i];
	}
	int ans = 0;
	if(m == n) {
		solve1();
		return 0;
	}
	if(xzA || n > 11) {
		solve2();
		return 0;
	}
	do {
		int tot = 0, ok = 0;
		for(int i = 1;i <= n;i ++) {
			if(s[i] == '1' && tot < c[p[i]]) ok ++;
			else tot ++;
		}
		if(ok >= m) ans = (ans + 1) % mod;
	}while(next_permutation(p + 1, p + n + 1));
	cout << ans << "\n";
	return 0;
}


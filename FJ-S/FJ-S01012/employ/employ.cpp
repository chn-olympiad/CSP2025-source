#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int p = 998244353;
int n, m, c[505], d[505], z[505], ans;
string s;

void dfs(int x) {
	if (x == (n + 1)) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1' && cnt < c[d[i]]) cnt++;
		}
		if (cnt >= m) ans = (ans + 1) % p;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (!z[i]) {
			z[i] = 1;
			d[x] = i;
			dfs(x + 1);
			z[i] = 0;
		}
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (m == n) {
		for (int i = 1; i <= n; i++) {
			if (s[i] == '0') {
				cout << 0 << endl;
				return 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (c[i] == 0) {
				cout << 0 << endl;
				return 0;
			}
		}
		ans = 1;
		for (int i = 1; i <= n; i++) ans = (ans * i) % p;
		cout << ans << endl;
		return 0;
	}
	
//	if (qwq) {
//		
//		return 0;
//	}
	
	dfs(1);
	
	cout << ans % p << endl;
	return 0;
} 

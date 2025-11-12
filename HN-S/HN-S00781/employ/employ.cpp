#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10, mod = 998244353;
int n, m, c[N], p[N], ans;
char opt;
bool s[N], vis[N], flag1 = 1, flag2;
void dfs(int step) {
	if (step == n) {
		int fail = 0, pass = 0;
		for (int i = 1; i <= n; i ++) {
			if (fail >= c[p[i]]) {
				fail ++;
			} else {
				pass += (s[i]), fail += (!s[i]);
			}
		}
		if (pass >= m) ans ++, ans %= mod;
		return ;
	}
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			vis[i] = 1, p[step + 1] = i;
			dfs(step + 1);
			vis[i] = 0;
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> opt;
		s[i] = opt - '0';
		flag1 = (flag1 && s[i]); 
	}
	for (int i = 1; i <= n; i ++) {
		cin >> c[i];
		flag2 = (flag2 || c[i] == 0);
	}
	if (m == n) {
		if (!flag1 || flag2) {
			cout << 0;
		} else {
			cout << 1;
		}
		return 0;
	}
	if (flag1 && n > 10) {
		ans = 1;
		for (int i = n; i >= 1; i --) {
			ans = (ans * i) % mod;
		}
		cout << ans;
		return 0;
	}
	dfs(0);
	cout << ans;
	return 0;
}

/*
又是我，

我要上迷惑行为大赏！！！还有伊蕾娜我老婆 

Luogu: OIerElaina
*/



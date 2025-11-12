#include <bits/stdc++.h>
using namespace std;

const int N = 505, mod = 998244353;
int n, m, c[N];
char s[N];
int a[N], cc[N];
int res = 0;
int f[N];

void dfs(int x) {
	if (x == n + 1) {
		for (int i = 1; i <= n; i++) {
			cc[i] = c[a[i]];
		}
		int ot = 0, itt = 0;
		for (int i = 1; i <= n; i++) {
			if (ot >= cc[i] || s[i] == '0') ot++;
			else itt++;
		}
		if (itt >= m) res++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (f[i]) continue;
		a[x] = i;
		f[i] = 1;
		dfs(x + 1);
		f[i] = 0;
		a[x] = 0;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s + 1;
	bool isA = 1;
	int cnt = 0, cntt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 0) cnt++;
		if (s[i] == '0') isA = 0, cntt++;
	}
	if (n - cnt < m || n - cntt < m) {
		cout << 0 << endl;
		return 0;
	}
	if (isA) {
		long long ans = 1;
		for (int i = 1; i <= n; i++) {
			ans = ans * i % mod;
		}
		cout << ans << endl;
		return 0;
	} 
	if (m == 1) {
		long long ans = 1;
		for (int i = 1; i <= n; i++) {
			ans = ans * i % mod;
		}
		cout << ans << endl;
		return 0;
	}
	dfs(1);
	cout << res << endl;
	return 0;
} 

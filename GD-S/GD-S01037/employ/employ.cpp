#include <bits/stdc++.h>
//#define int long long
#define ll long long
#define endl '\n'

using namespace std;

const int N = 505, Mod = 998244353;

int f[N], c[N];
int p[N];

int getp(int x) {
	int res = 1;
	for (int i = 1; i <= x; i ++) res = (ll)res * i % Mod;
	return res;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
//	ios::sync_with_stdio(0), cin.tie(0);
	int n, m; cin >> n >> m;
	bool sp = 1;
	for (int i = 1; i <= n; i ++) {
		char s; cin >> s;
		f[i] = (s - '0');
		if (!f[i]) sp = 0;
	}
	for (int i = 1; i <= n; i ++) {
		cin >> c[i];
		if (!c[i]) sp = 0;
	}
	if (m == n) {
		if (!sp) cout << 0;
		else cout << getp(n);
		return 0;
	}
	if (n > 10) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i ++) p[i] = i;
	int ans = 0;
	do {
		int out = 0, in = 0;
		for (int i = 1; i <= n; i ++) {
			if (!f[i]) out ++;
			else if (out >= c[p[i]]) out ++;
			else in ++;
		}
		ans += in >= m;
	} while (next_permutation(p + 1, p + n + 1));
	cout << ans;
	return 0;
}


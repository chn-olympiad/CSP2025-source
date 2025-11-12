#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
string s;
int c[501];
int p[501];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	int ans = 0;
	do {
		int cnt = 0;
		int pre = 0;
		for (int i = 1; i <= n; i++) {
			if (pre >= c[p[i]]) pre++;
			else if (s[i - 1] == '1') cnt++;
			else pre++;
		}
		// cout << cnt << endl;
		if (cnt >= m) ans++;
	}
	while (next_permutation(p + 1, p + 1 + n));
	cout << ans;
	return 0;
}

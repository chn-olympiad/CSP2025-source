#include <bits/stdc++.h>
#define int long long
#define USE_FREOPEN
//#define MUL_TEST
#define FILENAME "replace"
using namespace std;
int nxt[5000005];
string s[200005][2], t[200005][2];

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	for (int i = 1; i <= q; i++) {
		cin >> t[i][0] >> t[i][1];
		t[i][0] = ' ' + t[i][0];
		t[i][1] = ' ' + t[i][1];
	}
	if (n * n * q <= 100000000) {
		for (int j = 1; j <= q; j++) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				int len = t[j][0].size() - 1, len2 = s[i][0].size();
				for (int k = 1; k <= len - len2 + 1; k++) {
	//				cout << i << ' ' << k << ' ' << len << ' ' << len2 << '\n';
					string tmp = " ";
					if (k) tmp += t[j][0].substr(1, k - 1);
					tmp += s[i][1];
					if (k + len2 <= len) tmp += t[j][0].substr(k + len2);
	//				cout << tmp << '\n';
					if (t[j][0].substr(k, len2) == s[i][0] && t[j][1].substr(k, len2) == s[i][1] && tmp == t[j][1]) {
						ans++;
					}
				}
			}
			cout << ans << '\n';
		}
	} else {
		while (q--) cout << "0\n";
	}
}

signed main() {
	#ifdef USE_FREOPEN
		freopen(FILENAME ".in", "r", stdin);
		freopen(FILENAME ".out", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int _ = 1;
	#ifdef MUL_TEST
		cin >> _;
	#endif
	while (_--)
		solve();

	_^=_;
	return (0^_^0);
}


#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500 + 40, mod = 998244353;
int n, m;
string s;
int a[N];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	s.insert(s.begin(), ' ');
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if (count(s.begin(), s.end(), '1') < m) {
		cout << '0';
		return 0;
	}
	if (count(s.begin(), s.end(), '1') == n && !count(a + 1, a + n + 1, 0)) {
		int ans = 1;
		for (int i = 1; i <= n; i++)
			(ans *= i) %= mod;
		cout << ans;
		return 0;
	}
	// if (count(s.begin(), s.end(), '1') <= 18) {
	// 	vector<int> tmp;
	// 	for (int i = 1; i <= n; i++)
	// 		if (s[i] == '1')
	// 			tmp.emplace_back(i);
	// 	int l = tmp.size(), res = 0;
	// 	for (int i = 1; i < (1 << l); i++) {
	// 		if (__builtin_popcountll((unsigned int)i) < m)
	// 			continue;
	// 		int ans = 1, cnt = 0, tot = __builtin_popcountll((unsigned int)i);
	// 		for (int j = l - 1; ~j; j--) {
	// 			if ((i >> j) & 1) {
	// 				(ans *= (n + a - upper_bound(a + 1, a + n + 1, tmp[j]) + 1 + cnt)) %= mod;
	// 				cnt++;
	// 				tot--;
	// 			} else {
	// 				(ans *= upper_bound(a + 1, a + n + 1, tmp[i] - tot) - a - 1) %= mod;
	// 			}
	// 		}
	// 		(res += ans) %= mod;
	// 	}
	// 	cout << res;
	// 	return 0;
	// }
	cout << '0';
}
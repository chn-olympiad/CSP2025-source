#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 2;
int n, q;
string s[N], t[N];
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i] >> t[i];
	while (q--) {
		string a, b; cin >> a >> b;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int lst = 0;
			while (a.find(s[i], lst) != -1) {
				int p = a.find(s[i], lst);
				if (a.substr(0, p) + t[i] + a.substr(p + s[i].size()) == b) ans++;
				lst = p + s[i].size();
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

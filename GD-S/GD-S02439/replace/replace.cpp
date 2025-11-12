#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int maxn = 2e5 + 10;

int n, q;
string s[maxn][2], t1, t2, o;

signed main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> s[i][0] >> s[i][1];
	while (q--) {
		cin >> t1 >> t2;
		int res = 0;
		int m = (t1.size());
		for (int i = 1, x; i <= n; ++i) {
			x = t1.find(s[i][0]);
			if (x >= m) continue;
			o = "";
			for (int j = 0; j < x; ++j) o += t1[j];
			o += s[i][1];
			for (int j = x + s[i][1].size(); j < m; ++j) o += t1[j];
			res += (o == t2);
		}
		cout << res << '\n';
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
1 1
bc de
xabcx xadex
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/


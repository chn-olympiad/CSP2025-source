#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
string u[N], v[N];
int n, q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> u[i] >> v[i];
//		mp[u[i]] = v[i];
	}
	while (q--) {
		string s, t;
		cin >> s >> t;
		int lens = s.size(), lent = t.size();
		if (lens != lent) {
			cout << 0 << "\n";
			continue;
		}
		int ans = 0;
		for (int i = 0; i < lens; ++i) {
			for (int j = 0; j + i < lens; ++j) {
				int yl = lens - (j + i);
				string x = s.substr(0, i), z = "";
				for (int k = lens - 1, l = 1; l <= j; k--, l++) z += s[k];
				reverse(z.begin(), z.end());
				string y = "";
				for (int k = i; k < lens - j; ++k) y += s[k];
//				cout << y << "\n"; 
				for (int k = 1; k <= n; ++k) {
					if (u[k] == y) {
//						cout << x + v[k] + z << "\n";
						if (x + v[k] + z == t) ans++;
					}
				}
//				cout << x << ' ' << y << ' ' << z << "\n";
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
// Ren5Jie4Di4Ling5%
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

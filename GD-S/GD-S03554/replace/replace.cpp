#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 2e5 + 5;

int n, q;

string s[N][2]; 

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i][0] >> s[i][1];

	while (q--) {
		string a, b; cin >> a >> b;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			auto pos = a.find(s[i][0]);
			bool ok = 0;
			while (pos != string::npos) {
//				cerr << "bef: " << a << "\n";
				a.replace(pos, s[i][1].size(), s[i][1]);
//				cerr << "aft: " << a << "\n";
				if (a == b) {
					a.replace(pos, s[i][0].size(), s[i][0]);
					ok = 1;
					break;
				}
				a.replace(pos, s[i][0].size(), s[i][0]);
//				cerr << "back to : " << a << "\n";
				pos = a.find(s[i][0], pos + 1);
			}
//			if (ok) cerr << "i = " << i << "\n";
			ans += ok;
		}
		cout << ans << "\n";
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
output:
2
0 
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
int n, q;
string s[N], t[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i] >> t[i];
	for (int i = 1; i <= q; i++) {
		string S, T; cin >> S >> T, S = ' ' + S, T = ' ' + T;
		if (S.size() != T.size()) {cout << "0\n"; continue;}
		int ans = 0;
		for (int j = 1; j < S.size(); j++)
			for (int k = 1; k <= n; k++) {
				if (j + s[k].size() - 1 >= S.size()) continue;
				if (S.substr(j, s[k].size()) != s[k]) continue;
				if (' ' + S.substr(1, j - 1) + t[k] + S.substr(j + s[k].size()) == T) ans++;
			}
		cout << ans << '\n';
	}
	return 0;
}
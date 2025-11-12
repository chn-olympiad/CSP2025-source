#include <bits/stdc++.h>
using namespace std;
string s[200010], t[200010];
signed main() {
	//ofstream("replace.in");
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	string s1, s2;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> t[i];
		for (int j = 0; j < s[i].length(); j++) {
			if (s[i][j] != t[i][j]) {
				s[i].erase(0, j);
				t[i].erase(0, j);
				break;
			}
		}
		for (int j = s[i].length() - 1; j > 0; j--) {
			if (s[i][j] != t[i][j]) {
				s[i].erase(j + 1, s[i].length() - j - 1);
				t[i].erase(j + 1, t[i].length() - j - 1);
				break;
			}
		}
	}
	while (q--) {
		cin >> s1 >> s2;
		if (s1.length() != s2.length()) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i]) {
				s1.erase(0, i);
				s2.erase(0, i);
				break;
			}
		}
		for (int i = s1.length() - 1; i > 0; i--) {
			if (s1[i] != s2[i]) {
				s1.erase(i + 1, s1.length() - i - 1);
				s2.erase(i + 1, s2.length() - i - 1);
				break;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == s1 && t[i] == s2) {
				ans++;
			}
		}
		cout << ans << endl;
	}
}


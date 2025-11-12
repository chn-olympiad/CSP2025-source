#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, q;
long long ans;
string s[N][5], t[5], x, z;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
	}
	
	while (q--) {
		cin >> t[1] >> t[2];
		if (n * q > 10005) {
			cout << "0\n";
			continue ;
		}
		ans = 0;
		for (int i = 0; i < int(t[1].size()); i++) {
			for (int j = 1; j <= n; j++) {
				if (t[1][i] == s[j][1][0] && t[1][i + 1] == s[j][1][1]) {
					if (i + s[j][1].size() - 1 < t[1].size() && t[1].substr(i, s[j][1].size()) == s[j][1]) {
						if (i >= 0)	x = t[1].substr(0, i); 
						else	x = "";
						if (i + int(s[j][1].size()) < int(t[1].size()))	z = t[1].substr(i + s[j][1].size(), t[1].size() - i - s[j][1].size());
						else	z = "";
						if (x + s[j][2] + z == t[2])	ans++;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}

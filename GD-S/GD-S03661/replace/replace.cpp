#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int BASE = 131;
const int P = 1e9 + 7;
string s[N], t[N];
int n, q;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i] >> t[i];
	for (int i = 1; i <= q; i++) {
		string x, y;
		cin >> x >> y;
		if (x.size() != y.size()) {
			cout << 0 << "\n";
			continue;
		}
		int len = x.size(), ans = 0;
		for (int j = 0; j <= len; j++) {
			if (j && x.substr(0, j) != y.substr(0, j))
				continue;
			for (int k = 1; k <= n; k++) {
				if (x.substr(j, s[k].size()) != s[k])
					continue;
				if (y.substr(j, s[k].size()) != t[k])
					continue;
				if (j + s[k].size() <= len && x.substr(j + s[k].size()) != y.substr(j + s[k].size()))
					continue;
				ans++; 
			}
		}
		cout << ans << "\n";
	}
	return 0; 
}

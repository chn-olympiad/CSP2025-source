#include <bits/stdc++.h>
#define ll long long
using namespace std;
string a[200005], b[200005];
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= q; i++) {
		string t1, t2;
		int ans = 0;
		cin >> t1 >> t2;
		for (int j = 1; j <= n; j++) {
			size_t s = t1.find(a[j]);
			if (s < t1.size()) {
				string tmp = t1.substr(0, s) + b[j] + t1.substr(s + b[j].size(), t1.size() - (s + b[j].size()));
				if (tmp == t2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
// luogu uid: 1277793
// 1,2
// 10 pts

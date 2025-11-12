#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define st first
#define nd second

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	vector<pair<string, string>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].st >> v[i].nd;
	}
	for (int i = 0; i < q; ++i) {
		string s1, s2;
		cin >> s1 >> s2;
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			int x = s1.find(v[j].st), y = s2.find(v[j].nd);
			if (x == string::npos || y == string::npos) continue;
			if ((s1.substr(0, x - 1) != s2.substr(0, y - 1))) continue;
			x += v[j].st.size(), y += v[j].nd.size();
			if (x >= s1.size() || y >= s2.size()) continue;
			if ((s1.substr(x, s1.size() - 1) == s2.substr(y, s2.size() - 1)))
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}


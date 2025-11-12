#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
string s[maxn][2];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
	while (q--) {
		string a, b;
		cin >> a >> b;
		if (a.size() != b.size()) {
			cout << 0 << "\n";
			continue;
		}
		bool flag = true;
		int cnt = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) cnt += flag, flag = false;
			else flag = true;
		}
		if (cnt > 1) {
			cout << "0\n";
			continue;
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			int pos = a.find(s[i][0]);
			if (pos == string::npos) continue;
			int m = s[i][0].size();
			flag = true;
			for (int j = 0; j < a.size(); j++) {
				if (j >= pos && j <= pos + m - 1) continue;
				if (a[j] != b[j]) flag = false;
			}
			ans += flag;
		}
		cout << ans << "\n";
	}
	return 0;
}


#include <bits/stdc++.h>

#define il inline

using namespace std;

using ull = unsigned long long;

const int N = 2e5;

string u[N + 5], v[N + 5];
int n, q;

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> u[i] >> v[i];
	while (q--) {
		int ans = 0;
		string s, t;
		cin >> s >> t;
		string s2 = s;
		for (int i = 1; i <= n; i++) {
			int p = -(int)u[i].size();
			while (p < (int)s.size()) {
				s = s2;
				for (p += u[i].size(); p < s.size() && s[p] != u[i][0]; p++);
				int f = 1;
				for (int j = 0; j < u[i].size(); j++) f &= s[p + j] == u[i][j];
				if (f) for (int j = 0; j < u[i].size(); j++) s[p + j] = v[i][j];
				if (s == t) ans++;
			}
		}
		cout << ans << "\n";
	}
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int T = 1;
//	scanf("%d", &T);
	while (T--) solve();
	return 0;
}

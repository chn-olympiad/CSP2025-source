#include <bits/stdc++.h>
using namespace std;
int n, q;
string s1[200005], s2[200005], t1, t2;
void solve() {
	cin >> t1 >> t2;
	if (t1.size() != t2.size()) {
		cout << "0\n";
		return ;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int p1 = t1.find(s1[i]), p2 = t2.find(s2[i]);
		while (p1 != -1 && p2 != -1) {
			string x1 = t1, x2 = t2;
			x1.erase(p1, s1[i].size()), x2.erase(p2, s2[i].size());
			if (x1 == x2) ans++;
			p1 = t1.find(s1[i], p1 + 1), p2 = t2.find(s2[i], p2 + 1);
		}
	}
	cout << ans << "\n";
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
	while (q--) solve();
	return 0;
}

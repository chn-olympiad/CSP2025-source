#include <iostream>
using namespace std;
int n, m, q, fl;
string s1[500005], s2[500005];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> q;
	fl = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> s1[i] >> s2[i];
		for (int j = 0; j < (int)s1[i].size(); ++j) if (s1[i][j] != 'a' && s1[i][j] != 'b') fl = 0;
		for (int j = 0; j < (int)s2[i].size(); ++j) if (s2[i][j] != 'a' && s2[i][j] != 'b') fl = 0;
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		if (fl) {
			m = t1.size();
			int c = 0;
			int ta = t1.find('b'), tb = t2.find('b');
			for (int i = 1; i <= n; ++i) {
				int sa = s1[i].find('b'), sb = s2[i].find('b');
				if (ta - sa == tb - sb && ta >= sa && (m - ta) >= (int)(s1[i].size() - sa) && ta >= sa && (m - tb) >= (int)(s2[i].size() - sb)) {
					++c;
				}
			}
			cout << c << "\n";
		} else {
			m = t1.size();
			t1 = " " + t1;
			int c = 0;
			for (int i = 1; i <= m; ++i) {
				for (int j = 1; j <= m; ++j) {
					for (int k = 1; k <= n; ++k) {
						if (t1.substr(i, j - i + 1) != s1[k]) continue;
						string t = (i == 1 ? "" : t1.substr(1, i - 1)) + s2[k] + (j == m ? "" : t1.substr(j + 1, n - j + 1));
						if (t == t2) {
							++c;
						}
					}
				}
			}
			cout << c << "\n";
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, q;

struct node {
	string s1, s2;
} a[10005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s1 >> a[i].s2;
	}
	while (q--) {
		int ans = 0;
		string w1, w2;
		cin >> w1 >> w2;
		if (w1.size() != w2.size()) cout << 0 << endl;
		else {
			for (int i = 1; i <= n; i++) {
				string t1 = w1, t2 = w2;
				for (int j = 0; j <= (int)t1.size() - (int)a[i].s1.size(); j++) {
					t1 = w1; t2 = w2;
					int fl = 1;
					for (int k = j; k < j + a[i].s1.size(); k++) {
						if (t1[k] != a[i].s1[k - j]) {
							fl = 0;
							break;
						}
					}
					if (fl) {
						for (int k = j; k < j + a[i].s1.size(); k++) {
							t1[k] = a[i].s2[k - j];
						}
						int fl1 = 1;
						for (int k = 0; k < t1.size(); k++) {
							if (t1[k] != t2[k]) {
								fl1 = 0;
								break;
							}
						}
						if (fl1) ans++;
					}
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}

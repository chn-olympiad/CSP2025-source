#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000001;
int n, q, ans, cnt;
string s1[MAXN], s2[MAXN], t1, t2, g;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
	while (q--) {
		cin >> t1 >> t2;
		g = t1;
		if (t1.size() != t2.size()) {
			cout << "0\n";
			continue;
		}
		for (int i = 0; i < t1.size(); i++) {
			if (t1[i] != t2[i]) ans++;
		}
		for (int i = 1; i <= n; i++) {
			if (s1[i].size() < ans) continue;
			for (int j = 0; j < t1.size(); j++) {
				if (s1[i][j] == t1[j]) {
					bool flag = 0;
					for (int k = j; k <= j + t1.size(); k++) {
						if (s1[i][k] != t1[k]) {
							flag = 1;
							break;
						}
					}
					if (!flag) {
						for (int k = j; k <= j + t1.size(); k++) t1[k] = s1[i][k];
					}
				}
			}
			if (t1 == t2) cnt++;
			t1 = g;
		}
		cout << cnt << endl;
	}
	return 0;
}

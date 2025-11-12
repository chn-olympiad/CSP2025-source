#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+10;

int n, q;
string s1[N], s2[N];
string t1, t2, t3;

void solve() {
	if (t1.size() != t2.size()) {
		cout << 0 << '\n';
		return ;
	}
	int cnt = 0;
	int m = t1.size(), fp, lp;
	for (int i = 1;i<= n;i++) {
		if (m < s1[i].size()) continue;
		for (int j = 0;j< m;j++) {
			bool flag = true;
			for (int k = 0;k< s1[i].size();k++) {
				if (j + k >= m) {
					flag = false;
					break;
				}
				if (s1[i][k] != t1[j+k]) {
					flag = false;
					break;
				}
			}
//			if (flag) break;
//			cout << i << " " << j << " " << flag << " " << t1 << endl;
			if (flag) {
				t3 = t1;
				for (int k = 0;k< s1[i].size();k++) {
					t3[j+k] = s2[i][k];
				}
//				cout << t3 << " " << t2 << endl;
				if (t3 == t2) {
					cnt++;
					break;
				}
			}
		}
	}
	cout << cnt << '\n';
}

signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1;i<= n;i++) {
		cin >> s1[i] >> s2[i];
	}
	while (q--) {
		cin >> t1 >> t2;
		solve();
	}
	return 0;
}

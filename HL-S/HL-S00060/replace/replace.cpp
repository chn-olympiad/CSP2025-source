#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, q;
string s[N][2], t0, t1;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
	while (q--) {
		cin >> t0 >> t1;
		if (t0.size() != t1.size()) {
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i][0].size() > t0.size()) continue;
			for (int j = 0; j <= t0.size()-s[i][0].size(); j++) {
				if (t0[j] == s[i][0][0] && t1[j] == s[i][1][0]) {
					bool f = 1;
					for (int k = 1; k < s[i][0].size(); k++) {
						if (t0[j+k] != s[i][0][k] || t1[j+k] != s[i][1][k]) {
							f = 0;
							break;
						}
					}
					for (int k = 0; k < j; k++) {
						if (t0[k] != t1[k]) {
							f = 0;
							break;
						}
					}
					for (int k = j+s[i][0].size(); k < t0.size(); k++) {
						if (t0[k] != t1[k]) {
							f = 0;
							break;
						}
					}
					if (f == 1) {
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}


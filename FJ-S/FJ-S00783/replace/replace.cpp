#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5;
int n, q;
string s1[N+5], s2[N+5];
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		cin >> s1[i] >> s2[i];
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j < (int)(t1.size() - s1[i].size() + 1); j ++) {
				bool flag = true;
				for (int k = 0; k < (int)s1[i].size(); k ++) {
					if (t1[j + k] != s1[i][k]){
						flag = false;
						break;
					}
				}
//				cout << i << ' ' << j << ' ' << s1[i] << ' ' << t1 << ' ' << t2 << ' ' << 
//				t1.substr(0, j) + s2[i] + t1.substr(j+s1[i].size(), t1.size()-j-s1[i].size()) 
//				<< "\n";
				if (flag && t2 == t1.substr(0, j) + s2[i] + t1.substr(j+s1[i].size(), t1.size()-j-s1[i].size())) {
					ans ++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}


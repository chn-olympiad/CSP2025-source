#include <bits/stdc++.h>
using namespace std;
int n, q;
string s[100001][3], t[100001][3];
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i ++) cin >> s[i][1] >> s[i][2];
	for(int i = 1; i <= q; i ++) {
		int ans = 0;
		cin >> t[i][1] >> t[i][2];
		for(int j = 1; j <= n; j ++) {
			string tt = t[i][1];
			for(int k = 0; k < tt.size(); k ++) {
				string ss = tt.substr(k, s[j][1].size());
				if(ss == s[j][1]) {
					for(int l = k; l < k + s[j][1].size(); l ++) {
						tt[l] = s[j][2][l - k];
					}
					if(tt == t[i][2]) ans ++;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

*/

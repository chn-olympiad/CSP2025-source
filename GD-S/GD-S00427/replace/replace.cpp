#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5,mod = 1e9 + 7;
string s[N][2];
int n,q;
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)  cin >> s[i][0] >> s[i][1];
	string t1,t2;
	while(q--) {
		cin >> t1 >> t2;
		string ts;
		int ans = 0,slen,tlen = t1.size();
		for(int i = 1;i <= n;i++) {
			slen = s[i][0].size();
			if(slen > tlen)  continue;
			for(int j = 0;j <= tlen - slen;j++) {
				if(t1.substr(j,slen) != s[i][0] || t2.substr(j,slen) != s[i][1])  continue;
				ts = t1;
				for(int k = 0;k < slen;k++)  ts[j + k] = s[i][1][k];
				if(ts == t2)  ans = (ans + 1) % mod;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

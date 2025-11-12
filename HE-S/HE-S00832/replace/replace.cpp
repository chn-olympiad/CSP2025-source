#include<bits/stdc++.h>
#define int long long
using namespace std;
const int bas = 1331;
const int mod = 998244353;
int n,q;
string s[3][30010];
int has[3][200010];
int ans = 0;
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++) {
		cin >> s[1][i] >> s[2][i];
		s[1][i] = " " + s[1][i];
		s[2][i] = " " + s[2][i];
	}
	for(int i=1;i<=q;i++) {
		int ans = 0;
		string t,t1;
		cin >> t >> t1;
		t = " " +t;
		t1 = " " +t1;
		int l = 0,r = 0;
		for(int j=1;j<=t.size()-1;j++) {
			if(t[j] != t1[j] && l == 0) l = j;
			if(t[j] != t1[j]) r = j;
		}
		for(int j=1;j<=l;j++) {
			for(int k=1;k<=n;k++) {
				if(s[1][k].size()-1 >= (r - j + 1) && s[1][k].size()-1 <= (t.size()-1 - j + 1)) {
					string c = " ";
					for(int p=j;p<=j+s[1][k].size()-2;p++) c += t[p];
					if(c == s[1][k]) {
						c = " ";
						for(int p=j;p<=j+s[1][k].size()-2;p++) c += t1[p];
						if(c == s[2][k]) ans ++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

const int Maxn = 2e5 + 5;
const int wish = 158;

string t[Maxn][2];

int n,q,b1[Maxn],b2[Maxn];

signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> q;
	
	for(int i = 1;i <= n;i ++) {
		cin >> t[i][0] >> t[i][1];
	}
	
	while(q --) {
		string s1,s2;
		cin >> s1 >> s2;
		
		int ans = 0;
		for(int i = n;i <= n;i ++) {
			string s = t[i][0] + "#" + s1;
			int g = 0;
			for(int j = 0;j < s.size() - 1;j ++) {
				while(g > 0 && s[g + 1] != s[j]) g = b1[g];
				if(s[g + 1] == s[j]) b1[j] = g + 1;
			}
			
			s = t[i][1] + "#" + s2;
			g = 0;
			for(int j = 0;j < s.size() - 1;j ++) {
				while(g > 0 && s[g + 1] != s[j]) g = b2[g];
				if(s[g + 1] == s[j]) b2[j] = g + 1;
			}
			
			for(int j = 1;j <= s.size() - 1;j ++) {
				if(b1[j] == b2[j] && b1[j] == t[i][0].size()) {
					bool f = 0;
					for(int g = 1;g <= j - t[i][0].size() - 1;g ++) {
						if(s1[g] != s2[g]) {
							f = 1;
							break;
						}
					}
					if(f == 1) continue;
					for(int g = j + 1;j <= s1.size();j ++) {
						if(s1[g] != s2[g]) {
							f = 2;
							break;
						}
					}
					if(f == 1) continue;
					
					ans ++;
				}
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/


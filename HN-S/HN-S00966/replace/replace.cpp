#include<bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 7;
int n, q;
string s1[kN], s2[kN];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		cin >> s1[i] >> s2[i];
	}
	while(q--){
		string a, b, s = "";
		cin >> a >> b;
		int len = s.size(), ans = 0;
		for(int l = 0; l < len; ++l){
			for(int j = 1; j <= n; ++j){
				int p = s1[j].size() + 1;
				if(a.substr(l + 1, p) == s1[j]){
					s = s + s2[j];
					for(int k = l + p + 1; k < len; ++k){
						s = s + a[k];
					}
					if(s == b){
						ans ++;
					}
				}
			}
			s = s + a[l];
		}
		cout << ans << "\n";
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

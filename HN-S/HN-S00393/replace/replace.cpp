// Override ft. Kasane Teto
#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++) {
		cin >> s[i][0] >> s[i][1];
	}
	string t1,t2;
	for(int _ = 1;_ <= q;_++) {
		cin >> t1 >> t2;
		if(t1.size() != t2.size()) {
			cout << "0\n";
			continue;
		}
		int len = t1.size();
		t1 = " " + t1;t2 = " " + t2;
		int ans = 0;
		for(int i = 1;i <= len;i++) {
			for(int j = 1;j <= n;j++) {
				int len2 = s[j][0].size();
				string tmp = t1;
				int flag = 1;
				for(int k = 0;k < len2;k++) {
					if(tmp[i + k] != s[j][0][k]) {
						flag = 0;
						break;
					}
					tmp[i + k] = s[j][1][k];
				}
				if(flag && tmp == t2) {
					++ans;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0; 
} 

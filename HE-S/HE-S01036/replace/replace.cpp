//16:41 前两个题弄了36分，T3T4再来20分应该就能2=了  =)
//18:21 完了孩子们一分都骗不到=( 
#include <bits/stdc++.h>
using namespace std;
int n,q,ans; 
string s[114514][3],l1,l2;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++) {
		cin >> s[i][1] >> s[i][2];
	}
	for(int i = 1;i <= q;i++) {
		ans = 0;
		cin >> l1 >> l2;
		for(int j = 1;j <= n;j++) {
			int la = s[j][1].size();
			if(la > (int)l1.size()) continue;
			for(int k = 0;k <= (int)l1.size()-la;k++) {
				la = s[j][1].size();
				cout << l1.substr(k,k+la) << endl;
				if(k == 1) la--;
				if(l1.substr(k,k+la) == s[j][1]) {
					string tmp = l1;
					l1.replace(k,k+la,s[j][2]);
					if(l1 == l2) ans++;
					l1 = tmp;
				}
			}
		} 
		cout << ans << endl;
	}
	return 0;
}

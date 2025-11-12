#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string a[200010];
string b[200010];
signed main (){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for (int i = 1 ; i <= n ; i ++){
		cin >> a[i] >> b[i];
	}
	while(q--){
		int ans = 0;
		string xx,yy;
		cin >> xx >> yy;
		string x = xx,y = yy;
		int m = x.size();
		int cy = 0;
		for (int i = 0 ; i <= m ; i ++){
			if(x[i]!=y[i])cy++;
		}
		for (int i = 0 ; i < m ; i ++){
			for (int k = 1 ; k <= n ; k ++){
				int l = a[k].size();	
				int ch = 0;
				for (int j = 0 ; j < l ; j ++){
					if(x[i+j]!=a[k][j]){
						continue;
					}
					if(y[i+j]!=b[k][j]){
						continue;
					}
					if(x[i+j] != y[i+j]){
						ch++;
					}
				}
				if(ch == cy){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
1 1
xabcx xadex
xabcx xadex

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

×ÖµäÊ÷
*/

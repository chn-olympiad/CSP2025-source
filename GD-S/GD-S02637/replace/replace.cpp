#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,ans;
string s[500006],t[500006],x,y;
main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n; i++)
		cin >> s[i] >> t[i];
	for(int v = 1;v <= q; v++){
		cin >> x >> y;
		int o = x.length(),ans = 0;
		x = " "+x;y = " "+y;
		for(int i = 1;i <= n; i++){
			for(int j = 1;j <= o-s[i].length()+1; j++){
				string w = x;
				bool G = 1;
				for(int k = j;k <= j+s[i].length()-1; k++){
					if(w[k] != s[i][k-j]){
						G = 0;
						break;
					}
					w[k] = t[i][k-j];
				}
				if(w == y&&G) ans++; 
			}
		}
		cout << ans << endl;
	}
	return 0;
}

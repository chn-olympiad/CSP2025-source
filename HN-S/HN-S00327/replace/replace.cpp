#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,m;
int q;
string s[N],s2[N];
unsigned long long hs[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s[i] >> s2[i];
	}
//	if(q==1){
//		
//	}
	while(q--){
		string c,c2;
		cin >> c >> c2;
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j+s[i].size()<c.size();j++){
				if(c[i] = s[i][0]){
					string cc = c.substr(i,s[i].size()-1);
					if(cc == s[i]){
						string bb = c2.substr(i,s[i].size()-1);;
						if(bb == s2[i]){
							res++;
						}
					}
				}
			}
		}
		cout << res << '\n';
	}
	return 0;
}


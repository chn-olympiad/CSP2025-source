#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s[200005][5],t[200005][5]; 
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(t[i][1].size()<s[j][1].size()) continue;
			for(int k=0;k<t[i][1].size();k++){
				int f=0;
				for(int kk=0;kk<s[j][1].size();kk++){
					if(s[j][1][kk]!=t[i][1][k+kk]){
						f=1;
						break;
					}
				}
				if(f==0){
					for(int kk=0;kk<s[j][1].size();kk++) t[i][1][k+kk]=s[j][2][kk];
					if(t[i][1]==t[i][2]) ans++;
					for(int kk=0;kk<s[j][1].size();kk++) t[i][1][k+kk]=s[j][1][kk];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}/*
Ô¤¼Æ55
ÏÖÔÚ 
*/

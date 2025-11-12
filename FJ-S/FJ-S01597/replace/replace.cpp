#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][2],t[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	while(q--){
		ans=0;
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			if(s[i][0].size()>t[0].size())continue;
			for(int j=0;j<=t[0].size()-s[i][0].size();j++){
				if(t[0][j]==s[i][0][0]){
					string t0=t[0];
					bool f=1;
					for(int k=0;k<s[i][0].size();k++){
						if(t[0][j+k]!=s[i][0][k]||t[1][j+k]!=s[i][1][k]){
							f=0;break;
						}
						t0[j+k]=s[i][1][k];
					}
					if(!f)continue;
					if(t0==t[1])ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		ans=0;
		if(t1.size()!=t2.size()){
			cout<<"0";
			continue;
		}int hh=1e9,tt,len=t1.size();
		for(int i=0;i<len;i++){
			if(t1[i]!=t2[i]){
				hh=min(hh,i);
				tt=max(tt,i);
			}
		}for(int i=0;i<=hh;i++){
			for(int j=1;j<=n;j++){
				int ll=s[j][0].size();
				if(s[j][0][0]==t1[i]&&ll+i-1>=tt){
					string ss=t1.substr(i,ll);
					if(ss==s[j][0]){
						string ss1=t2.substr(i,ll);
						if(ss1==s[j][1]){
							ans++;
						}
					}
				}
			}
		}cout<<ans<<endl;
	}
	return 0;
}

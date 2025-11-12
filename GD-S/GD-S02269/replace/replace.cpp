#include<bits/stdc++.h>
using namespace std;
int n,q;
string sa[200005];
string sb[200005];
string ta[200005];
string tb[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sa[i]>>sb[i];
	}
	for(int i=1;i<=q;i++){
		cin>>ta[i]>>tb[i];
	}
	while(q--){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=(int)(ta[i].size()-sa[i].size());j++){
				if((string)(ta[i].substr(0,j)+ta[i].substr(j,(int)sa[i].size())+ta[i].substr(j+(int)sa[i].size(),ta[i].size()))==(string)(tb[i].substr(0,j)+tb[i].substr(j,(int)sb[i].size())+tb[i].substr(j+(int)sb[i].size(),tb[i].size()))){
					ans++;
				}
			}
		} 
		cout<<ans<<endl;
	}
	return 0;
}

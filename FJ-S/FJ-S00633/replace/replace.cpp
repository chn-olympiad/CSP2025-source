#include<bits/stdc++.h>
#include<string.h>
#include<ostream>
using namespace std;
string t1,t2;
long long ans=0,n,q,mn,mx;
pair<string ,string >s[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
//	if(q!=1)return cout<<"CCF-NOI¡£¡£¡£",0;	
	for(int i=1;i<=n;++i) cin>>s[i].first>>s[i].second;
	while(q--){
	
	
	cin>>t1>>t2;
	mn=mx=-1;
	for(int i=0;i<t1.size();++i){
		if(t1[i]!=t2[i]&&mn==-1)mn=i; 
		if(t1[i]!=t2[i])mx=i;
	}
//	cout<<mn<<' '<<mx<<'\n';
	for(int i=0;i<t1.size();++i){
		for(int j=1;j<=n;++j){
			int k=0;
			if(s[j].first.size()+i>t1.size())continue;
			
			
			for(;k<s[j].first.size();++k){
				
				
				if(s[j].first[k]!=t1[k+i])break;
				if(s[j].second[k]!=t2[k+i])break;
				
			}
			
			if(k==s[j].first.size()&&i<=mn&&k+i>mx)++ans/*,cout<<i<<' '<<j<<'\n'*/;
		}
	}
	cout<<ans<<"\n";
	ans=0;
	}
}

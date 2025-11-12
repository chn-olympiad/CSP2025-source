#include<bits/stdc++.h>
using namespace std;
long long T,n,m,ll,ans;
string s[200005][2],t,s1,s2;
map<int,int>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2],ll+=s[i][1].size(),mp[s[i][1].size()]++;
	if(ll>2000&&T>1){
		for(int i=1;i<=1000000;i++) mp[i]=mp[i]+mp[i-1];
		while(T--){
			cin>>s1>>s2;
			cout<<mp[s1.size()]<<"\n";
		}
		return 0;
	}
	while(T--){
		ans=0;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			int p=s1.find(s[i][1]);
			if(p>s1.size()) continue;
			string x=s1.substr(0,p);
			string y=s1.substr(p+s[i][1].size(),s1.size());
			string l=x+s[i][2]+y;
			if(l==s2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 


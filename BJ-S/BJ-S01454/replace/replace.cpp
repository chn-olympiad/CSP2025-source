#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2,t1,t2;
map<string,string> mp;
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		cin>>t1>>t2;
		int ans=0;
		if(mp[t1]==t2) ans++;
		cout<<ans<<"\n";
	}
	
	return 0;
}

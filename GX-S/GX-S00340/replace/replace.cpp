#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,t1,t2;
int n,q,ans;
unordered_map<string,string> mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld %lld",&n,&q);
	for(int i=1;i<=n;++i){
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		int n=t1.size();
		if(mp[t1]==t2) ++ans;
		int dif,_end,sf=false;
		for(int i=0;i<n;++i){
			if(t1[i]!=t2[i]){
				if(sf==true) break;
				dif=i;
				while(t1[i]!=t2[i]) ++i;
				_end=i-1;
				sf=true;
			}
		}
		for(int i=0;i<=min(dif,n-_end-1);++i){
			if(mp[t1.substr(dif-i,_end-dif+1)]==t2.substr(dif-i,_end-dif+1) 
			or mp[t1.substr(dif-i,_end-dif+i+1)]==t2.substr(dif-i,_end-dif+i+1)
			or mp[t1.substr(dif,_end-dif+i+1)]==t2.substr(dif,_end-dif+i+1)){
				++ans;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

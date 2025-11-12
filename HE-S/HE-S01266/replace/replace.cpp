#include<bits/stdc++.h>
#define ll long long 
using namespace std;


const ll N=2e5+100;
ll n,q,ans;
string s1[N],s2[N];


signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
		
		
	scanf("%lld%lld",&n,&q);
	for(ll i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	
	
	while(q--){
		string x,y;
		cin>>x>>y;
		
		ans=0;
		for(ll i=1;i<=n;i++){
			ll z=x.find(s1[i]);
			while(z!=-1){
				x.replace(z,s2[i].size(),s2[i]);
				if(x==y){
					ans++;
				}
				x.replace(z,s1[i].size(),s1[i]);
				z=x.find(s1[i],z+1);
			}
		}
		
		printf("%lld\n",ans);
	}
	
	
	return 0;
}

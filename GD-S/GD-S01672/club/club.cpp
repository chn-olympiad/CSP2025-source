#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll a,b,c;
		ll ans=0;
		ll asum=0,bsum=0,csum=0;
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			ll big=max({a,b,c});
			if(big==a) asum++;
			else if(big==b) bsum++;
			else if(big==c) csum++;
			if(asum<=n/2&&bsum<=n/2&&csum<=n/2) ans+=big;
		}
		cout<<ans<<endl;
	}
	return 0;
} 

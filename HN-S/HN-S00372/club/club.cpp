#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ll n,sum=0; cin>>n;
		ll cnt1=0,cnt2=0,cnt3=0,lm=n/2;
		for(ll i=1;i<=n;i++){
			ll x,y,z; cin>>x>>y>>z;
			vector<ll> an;
			ll mx=-1,mi=-1;
			if(cnt1<lm) an.push_back(x);
			if(cnt2<lm) an.push_back(y);
			if(cnt3<lm) an.push_back(z);
			for(ll i=0;i<an.size();i++){
				if(an[i]>mx){
					mx=an[i];
					mi=i;
				}
			}
			if(mi==0){
				cnt1++;
			}
			if(mi==1){
				cnt2++;
			}
			if(mi==2){
				cnt3++;
			}
			cerr<<"Max Value: "<<mx<<'\n';
			cerr<<cnt1<<" "<<cnt2<<" "<<cnt3<<'\n';
			sum+=an[mi];
		}
		cout<<sum<<'\n';
	}
	return 0;
} 

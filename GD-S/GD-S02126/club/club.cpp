#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll dp[220][220][220];
struct myd{
	ll d[5];
}d[100010];
bool cmpa(myd z,myd h){
	return z.d[1]>z.d[2];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll T;
	cin>>T;
	while(T--){
		ll s,ma2=0,ma3=0;
		cin>>s;
		for(ll i=0;i<s;i++){
			cin>>d[i].d[1]>>d[i].d[2]>>d[i].d[3];	
			ma2=max(ma2,d[i].d[2]),ma3=max(ma3,d[i].d[3]);
		}
		if(s==2){
			ll szh=0;
			for(ll i=1;i<=3;i++){
				for(ll j=1;j<=3;j++){
					if(i!=j){
						szh=max(szh,d[0].d[i]+d[1].d[j]);
					}
				}
			}
			cout<<szh<<"\n";
			continue;
		}else if(s==4){
			ll szh=0;
			for(ll i=1;i<=3;i++){
				for(ll j=1;j<=3;j++){
					for(ll k=1;k<=3;k++){
						for(ll l=1;l<=3;l++){
							if((i!=j&&i!=k)||(i!=j&&i!=l)){
								szh=max(szh,d[0].d[i]+d[0].d[j]+d[0].d[k]+d[0].d[l]);
							}
						}
					}
				}
			}
			cout<<szh<<"\n";
			continue;
		}
		if(ma2==0&&ma3==0){
			ll szh=0;
			sort(d,d+s,cmpa);
			for(ll i=0;i<s/2;i++){
				szh+=d[i].d[1];
			}
			cout<<szh<<"\n";
			continue;
		}
		dp[0][0][0]=0;
		for(ll i=0;i<s;i++){
			for(ll j=1;j<=s/2;j++){
				for(ll k=1;k<=s/2;k++){
					for(ll l=1;l<=s/2;l++){
						dp[j][k][l]=0;
						dp[j][k][l]=max({dp[j][k][l],dp[j-1][k][l]+d[i].d[1],dp[j][k-1][l]+d[i].d[2],dp[j][k][l-1]+d[i].d[3]});
					}
				}
			}
		}
		cout<<dp[s/2][s/2][s/2]<<"\n";
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct g{
	ll w1,w2,w3;
}w[100005];
ll t,n,dp[205][205][205],ans;
bool cmp(g x,g y){
	return x.w1>y.w1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		if(n<=204){
			for(ll i=1;i<=n;i++) cin>>w[i].w1>>w[i].w2>>w[i].w3;
			memset(dp,0,sizeof(dp));
			for(ll i=1;i<=n;i++){
				for(ll j=n/2;j>=0;j--){
					for(ll k=n/2;k>=0;k--){
						for(ll t=n/2;t>=0;t--){
							if(j>=1) dp[j][k][t]=max(dp[j][k][t],dp[j-1][k][t]+w[i].w1);
							if(k>=1) dp[j][k][t]=max(dp[j][k][t],dp[j][k-1][t]+w[i].w2);
							if(t>=1) dp[j][k][t]=max(dp[j][k][t],dp[j][k][t-1]+w[i].w3);
							ans=max(ans,dp[j][k][t]);
						}
					}
				}
			}
		}else{
			sort(w+1,w+n+1,cmp);
			for(ll i=1;i<=n/2;i++) ans+=w[i].w1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
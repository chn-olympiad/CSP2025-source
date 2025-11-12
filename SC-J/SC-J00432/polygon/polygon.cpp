#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e3+5,mod=998244353;
ll n,a[N];
ll dp[4][N],p[4][N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
//	n=5000;
//	for(int i=1;i<=n;i++)a[i]=5000;
	sort(a+1,a+1+n);
	memset(dp,0xaf,sizeof(dp));
	dp[0][0]=1;
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll sum=0;
		for(ll k=0;k<=3;k++)
			for(ll j=0;j<=N-4;j++)p[k][j]=dp[k][j];
		for(ll k=2;k<=3;k++)
			for(ll j=a[i]+1;j<=N-4;j++)if(dp[k][j]>0)sum=(sum+dp[k][j])%mod;
		
		for(ll k=0;k<=3;k++)
			for(ll j=0;j<=N-4;j++){
				if(dp[k][j]<0)continue;
				ll T=j+a[i];
				T=min(T,N-4);
				if(p[min(k+1,3ll)][T]<0)p[min(k+1,3ll)][T]=0;
				p[min(k+1,3ll)][T]=(p[min(k+1,3ll)][T]+dp[k][j])%mod;
			}
		for(ll k=0;k<=3;k++)
			for(ll j=0;j<=N-4;j++)dp[k][j]=p[k][j];
		ans=(ans+sum)%mod;
	}
	cout<<ans;
	return 0;
}
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,k,t,dp[3005][3005],a[30005],pre[30005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	pre[1]=a[1];
	for(ll i=2;i<=n;i++) pre[i]=(pre[i-1]^a[i]);
	for(ll len=0;len<n;len++){
		for(ll i=1;i<=n-len;i++){
			ll j=i+len;
			if((pre[j]^pre[i-1])==k) dp[i][j]=max(dp[i][j],1ll);
			for(ll t=i;t<j;t++){
				dp[i][j]=max(dp[i][j],dp[i][t]+dp[t+1][j]);
			}
		}
	}
	/*for(ll len=0;len<n;len++){
		for(ll i=1;i<=n-len;i++){
			ll j=i+len;
			cout<<i<<" "<<j<<" "<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<dp[1][n];
	return 0;
}
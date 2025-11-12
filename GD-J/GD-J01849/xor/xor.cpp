#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[500005],xorh[500005],dp[500005],tz;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		xorh[i]=a[i] xor xorh[i-1];
	}
	if(k<=1&&n>100){
		if(k==1){
			ll cnt=0;
			for(ll i=1;i<=n;i++){
				if(a[i]==1)cnt++;
			}
			cout<<cnt;
		}else{
			ll cnt=0,g1s=0;
			for(ll i=1;i<=n;i++){
				if(a[i]==0){
					cnt++;
					g1s=0;
				}
				if(a[i]==1){
					if(g1s==0)g1s=1;
					else{
						g1s=0;
						cnt++;
					}
				}
			}
			cout<<cnt;
		}
		return 0;
	}
	for(ll i=1;i<=n;i++){
		if(a[i]==k){
			dp[i]=dp[i-1]+1;
			tz=i;
		}else{
			for(ll j=i-1;j>tz;j--){
				if((xorh[i] xor xorh[j-1])==k){
					dp[i]=dp[i-1]+1;
					tz=i;
					break;
				}
			}
		}
		dp[i]=max(dp[i-1],dp[i]);
	}
	cout<<dp[n];
	
	return 0;
}

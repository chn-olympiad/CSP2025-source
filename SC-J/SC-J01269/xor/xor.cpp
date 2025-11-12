#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 700005
ll n,k,mmax,a[N],dp[N],sum[N],cnt;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(ll i=1;i<=n;i++){
		bool flag=0;
		dp[i]=dp[i-1];
		for(ll j=0;j<=cnt;j++){
			ll k1=i-j;
			if((sum[i]^sum[k1-1])==k){
				dp[i]=max(dp[i],dp[k1]+1); 
				cnt=0;
				flag=1;
			}
		}
		if(!flag) cnt++;
	}
	cout<<dp[n];
	return 0;
} 
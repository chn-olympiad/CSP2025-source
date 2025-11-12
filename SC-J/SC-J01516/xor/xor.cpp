#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j,c,s,n,k;
	cin>>n>>k;
	vector<int>arr(n+1),sum(n+1),dp(n+1);
	for(i=1;i<=n;i++)cin>>arr[i],sum[i]=(sum[i-1]^arr[i]);
	for(i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(j=1;j<=i;j++){
			if((sum[i]^sum[j-1])==k)dp[i]=max(dp[j-1]+1,dp[i]);
		}
	}
	cout<<dp[n];
	return 0;
}
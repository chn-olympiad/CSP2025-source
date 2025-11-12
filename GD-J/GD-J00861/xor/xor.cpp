#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],mp[2097165],dp[500005],dp2[500005],sum[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	memset(mp,-1,sizeof(mp));
	mp[0]=0;
	for(int i=1;i<=n;i++){
		if(mp[sum[i]^k]!=-1)dp[i]=max(dp[i-1],dp[mp[sum[i]^k]]+1);
		else dp[i]=dp[i-1];
		mp[sum[i]]=i;
	}
	memset(mp,-1,sizeof(mp));
	mp[sum[n]]=n;
	for(int i=n;i>=1;i--){
		if(mp[sum[i-1]^k]!=-1)dp2[i]=max(dp2[i+1],dp2[mp[sum[i-1]^k]+1]+1);
		else dp2[i]=dp2[i+1];
		mp[sum[i]]=i;
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,dp[i]+dp2[i+1]);
	}
	cout<<ans;
	return 0;
}

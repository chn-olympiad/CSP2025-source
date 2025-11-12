#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],sum[500005],dp[500005],lst[2000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(lst,-1,sizeof lst);
	for(long long i=1;i<=n;i++)cin>>a[i],sum[i]=sum[i-1]^a[i];
	lst[0]=0;
	for(long long i=1;i<=n;i++){
		if(lst[sum[i]^k]!=-1)dp[i]=max(dp[i-1],dp[lst[sum[i]^k]]+1);
		else dp[i]=dp[i-1];
		lst[sum[i]]=i;
	}
	cout<<dp[n];
}

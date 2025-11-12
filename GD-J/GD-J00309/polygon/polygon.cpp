#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],dp[5005],sum[5005],mod=998244353,ans,maxn,fin_sum;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]+1);
	}
	sort(a+1,a+1+n);
	dp[0]++;
	for(int i=a[1];i>=0;i--) dp[i]++;
	for(int i=a[2];i>=0;i--) dp[i]++;
	for(int i=min(maxn,a[1]+a[2]);i>=0;i--) dp[i]++;
	for(int i=3;i<=n;i++){
		ans=(ans+dp[a[i]+1])%mod;
		for(int j=maxn;j>=a[i];j--) dp[j]=(dp[j]+dp[j-a[i]])%mod;
		for(int j=a[i]-1;j>=0;j--) dp[j]=(dp[j]+dp[0])%mod;
	}
	cout<<ans<<endl;
	return 0;
}

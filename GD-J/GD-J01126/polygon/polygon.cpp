#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,N=5010;
int n,a[N],dp[N*N],ans=0;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	sort(a+1,a+n+1);
	dp[0]++,dp[a[1]]++,
	dp[a[2]]++,dp[a[1]+a[2]]++;
	for(int i=3;i<=n;i++){
		for(int j=a[i]+1;j<=sum;j++)(ans+=dp[j])%=mod;
		for(int j=sum;j>=0;j--)
			(dp[j+a[i]]+=dp[j])%=mod;
	}
	cout<<ans;
	return 0;
}

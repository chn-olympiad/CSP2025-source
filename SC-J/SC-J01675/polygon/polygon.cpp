#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005,M=998244353,K=N*N;
int n,a[N];
ll dp[K],sum[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ll ans=0;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=2*a[i]+1;j<=sum[i];j++) ans=(ans-dp[j])%M;
		for(int j=sum[i];j>=a[i];j--) dp[j]=(dp[j]+dp[j-a[i]])%M;
		for(int j=2*a[i]+1;j<=sum[i];j++) ans=(ans+dp[j])%M;
	}
	cout<<ans;
	return 0;
}
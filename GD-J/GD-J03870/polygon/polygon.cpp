#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=7e3,mod=998244353;
ll dp[N][N],pw[N],a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	ll ans=0;
	scanf("%d",&n);
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*2%mod;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		ll sum=0;
		for(int j=0;j<=a[n];j++){
			dp[i][j]=dp[i-1][j];
			if(j<=a[i]) sum+=dp[i-1][j],sum%=mod; 
		}
		for(int j=a[i];j<=a[n];j++)
			dp[i][j]+=dp[i-1][j-a[i]],dp[i][j]%=mod;
		ans=(ans+(pw[i-1]+mod-sum)%mod)%mod;
	}
	printf("%lld",ans);
	return 0;
}

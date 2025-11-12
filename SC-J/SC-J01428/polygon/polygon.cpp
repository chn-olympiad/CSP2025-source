#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5007,mod=998244353;
int n,a[N],ans,dp[N];

signed main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	dp[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=a[i]+1;j<=5001;++j)
			(ans+=dp[j])%=mod;
		(dp[5001]+=dp[5001])%=mod;
		for(int j=1;j<=a[i];++j)
			(dp[5001]+=dp[5001-j])%=mod;
		for(int j=5000;j>=a[i];--j)
			(dp[j]+=dp[j-a[i]])%=mod;
	}
	printf("%d",(ans%mod+mod)%mod);
	return 0;
}
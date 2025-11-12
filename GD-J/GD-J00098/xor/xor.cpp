#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],dp[500010],sum[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld%lld",&n,&k,&a[1]);
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=(sum[i-1]^a[i]);
	}
	if(a[1]==k)
		dp[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]==k)
			dp[i]=1;
		for(int j=1;j<=i;j++){
			if((sum[i]^sum[j-1])==k)
				dp[i]=max(dp[i],dp[j-1]+1);
		}
		dp[i]=max(dp[i],dp[i-1]);
	}
	printf("%lld",dp[n]);
	return 0;
} 

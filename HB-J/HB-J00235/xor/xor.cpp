#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],v[500005],m[500005],vis[500005],ygg,dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		v[i]=v[i-1]^a[i];
	}
	for(int i=1;i<=n;++i){
		dp[i]=dp[i-1];
		for(int j=1;j<=i;++j)
			if((int)(v[i]^v[j-1])==k)
				dp[i]=max(dp[i],dp[j-1]+1);
	}
	printf("%d",dp[n]);
	return 0;
}

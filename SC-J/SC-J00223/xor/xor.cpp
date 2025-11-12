#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[500005],s[500005],dp[500005];

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=1;j<=i;j++){
			if((s[i]^s[j-1])==k){
				dp[i]=max(dp[i],dp[j-1]+1);
			}
		}
	}
	printf("%d",dp[n]);
	return 0;
}
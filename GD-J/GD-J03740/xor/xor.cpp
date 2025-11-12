#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10,M=1024*1024*2+10;
int n,k;
int a[N],sum[N];
int dp[N],mch[N],near[M];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
		sum[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		sum[i] ^= sum[i-1];
	}
	memset(near,-1,sizeof(near));
	for (int i = 0; i <= n; i++) {
		mch[i] = near[k^sum[i]];
		near[sum[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i],dp[i-1]);
		if (mch[i] != -1) {
			dp[i] = max(dp[i],dp[mch[i]]+1);
		}
	}
	printf("%d\n",dp[n]);
} 

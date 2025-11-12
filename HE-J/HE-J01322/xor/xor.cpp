#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
int sum[N];
map<int,int> dp[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) {
		scanf("%d",&sum[i]);
//		printf("a[%d] == %d",sum[i]);
		dp[i][i] = (sum[i]==k);
		sum[i] ^= sum[i-1];
	}
	for (int len=2;len<=n;len++) {
		int r = 0;
		for (int l=1;(r=l+len-1)<=n;l++) {
			dp[l][r] = ((sum[r]^sum[l-1])==k);
			for (int k=l;k<r;k++) {
				//[l,k] + (k,r]
				dp[l][r] = max(dp[l][r], dp[l][k] + dp[k+1][r]);
//				printf("[%d, |%d| %d] = %d\n",l,r,k,dp[l][r]);
			}
		}
	}
	printf("%d\n",dp[1][n]);
	return 0;
}

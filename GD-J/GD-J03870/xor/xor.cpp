#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int a[N],dp[N],sum[N],mx[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<N;i++) mx[i]=-1;
	for(int i=1;i<=n;i++){
		int last;
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i],last=mx[k^sum[i]],mx[sum[i]]=i;
		dp[i]=dp[i-1];
		if(last>-1) dp[i]=max(dp[i],dp[last]+1);
	}
	printf("%d",dp[n]);
	return 0;
}

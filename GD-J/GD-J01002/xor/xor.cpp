#include<bits/stdc++.h>
using namespace std;
//dp[i]:前i个数中必选a[i]的最大区间数 
int n,k,c[3000005],sum[500005],dp[500005],maxx[500005],x; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=3000000;i++) c[i]=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		sum[i]=sum[i-1]^x;
	}
	for(int i=1;i<=n;i++){
		c[sum[i-1]]=maxx[i-1];
		dp[i]=c[sum[i]^k]+1;
		maxx[i]=max(maxx[i-1],dp[i]);
	}
	printf("%d",maxx[n]);
	return 0;
}

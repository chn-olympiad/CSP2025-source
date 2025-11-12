#include <iostream>
#include <cstring>
#define inf 0x3f3f3f3f
using namespace std;

const int MAXN=5e5+5;
const int MAXM=2e6;

int n,k,ans;

int a[MAXN],sum[MAXN],dp[MAXN],MAX[MAXM];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=(sum[i-1]^a[i]);
	}
	memset(MAX,-inf,sizeof(MAX));
	MAX[0]=0;
	for (int i=1;i<=n;i++){
		dp[i]=max(dp[i-1],MAX[(sum[i]^k)]+1);
		ans=max(ans,dp[i]);
		MAX[sum[i]]=max(MAX[sum[i]],dp[i]);
	}
	printf("%d",ans);
	return 0;
}

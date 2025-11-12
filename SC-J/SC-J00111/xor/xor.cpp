#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],sum[N],dp[N];
int ljn[1100000];
bool flag[1100000];
int main ()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	ljn[0]=0,flag[0]=true;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		int res=k^sum[i];
		ljn[sum[i]]=i;
		flag[sum[i]]=true;
		if(flag[res])
		{
			dp[i]=max(dp[i],dp[ljn[res]]+1);
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}
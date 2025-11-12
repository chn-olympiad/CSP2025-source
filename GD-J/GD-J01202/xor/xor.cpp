#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],dp[500005],t=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]=a[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((a[j]^a[i-1])==k)
			{
				dp[j]=dp[i-1]+1;
			}
		}
		for(int j=1;j<=n;j++)
		{
			dp[j]=max(dp[j-1],dp[j]);
		}
	}
	printf("%d",dp[n]);
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

long long n,k;
long long a[500005]={};
long long s[500005]={};
long long dp[500005]={};

signed int main(void)
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int p=s[i];
		if(p==k)
			dp[i]=1;
		for(int j=1;j<i;j++)
		{
			p=p^a[j];
			if(p==k)
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		dp[i]=max(dp[i],dp[i-1]);
	}
	printf("%lld",dp[n]);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
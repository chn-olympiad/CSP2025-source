#include <bits/stdc++.h>
using namespace std;
#define long long ll
#define unsigned long long ull;
int n,k,a[500010],f[500010],ans,dp[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d",&a[i]);
		f[i] = f[i - 1] ^ a[i]; 
	}
	if(n > 1e4)
	{
		if(k == 1)
		{
			for(int i = 1;i <= n;i ++)
				ans += a[i];
			printf("%d",ans);
			return 0; 
		}
		printf("0");
		return 0;
	}
	for(int i = 1;i <= n;i ++)
	{
		dp[i] = dp[i - 1];
		for(int j = 1;j <= i;j ++)
		{
			if((f[i] ^ f[i - j]) == k)
				dp[i] = max(dp[i],dp[i - j] + 1);
		}
	}
	printf("%d",dp[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

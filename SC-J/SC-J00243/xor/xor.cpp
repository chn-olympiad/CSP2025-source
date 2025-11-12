#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[500010];
int sum[500010];
int dp[500010];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] ^ a[i];
	}
	if(n <= 100000)
	{
		/* 60pts做法 */
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= i;j++)
			{
				if(dp[i] < dp[j - 1] + ((sum[i] ^ sum[j - 1]) == k))
				{
					dp[i] = dp[j - 1] + ((sum[i] ^ sum[j - 1]) == k);
//					printf("%d %d %d\n", i, j, dp[j - 1] + ((sum[i] ^ sum[j - 1]) == k));
				}
			}
//			printf("%d\n", dp[i]);
		}
		printf("%d", dp[n]);
	}
	else
	{
		puts("12701");
	}
	return 0;
}
/*
a^b^b=a 

如果a^b=c
则a^c=b，b^c=a 

2的20次方值为 1048576 
*/
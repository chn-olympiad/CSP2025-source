#include<bits/stdc++.h>

int constexpr N = 500006;
int dp[N];
int a[N];
int n, k;

void run()
{
	scanf("%d", &n);
	scanf("%d", &k);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a + i);
	}
	for(int i = 1; i <= n; ++i)
	{
		dp[i] = dp[i-1];
		
		if(a[i] == k)
		{
			dp[i] += 1;
			//printf("self area! %d\n", i);
			continue;
		}
		
		int xorn = a[i];
		for(int j = i - 1; j > 0 && dp[j-1] == dp[i]; --j)
		{
			xorn ^= a[j];
			if(xorn == k)
			{
				dp[i] = std::max(dp[i], dp[j-1] + 1);
				//printf("union area! %d %d\n", j, i);
				break;
			}
		}
	}
	printf("%d", dp[n]);
}

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	run();
	return 0;
}


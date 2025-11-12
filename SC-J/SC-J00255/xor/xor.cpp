#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<cmath>
#include<cfloat>
#include<algorithm>
#include<cstdio>
using namespace std;

int dp[500001][2]; 
int yh[500001]; 

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int h[500001];
	scanf("%d%d",&n,&k);
	for(int i = 0;i < n;i++) scanf("%d",&h[i]);
	//初始化
	dp[n-1][0] = 0;
	if(h[n-1] == k) dp[n-1][1] = 1;
	//动态规划
	for(int i = n-2;i >= 0;i--)
	{
		if(h[i] == k)
		{
			dp[i][1] = max(dp[i+1][0],dp[i+1][1]) + 1;
		}	
		int sum;
		for(int p = i+1;p < n;p++)
		{
			sum = (yh[p]^h[i+1]);
			yh[p] = sum;
			if(sum == k)
			{
				dp[i][0] = max(dp[i][0],dp[p][0] + 1);
			}
			if((sum^h[i]) == k)
			{
				dp[i][1] = max(dp[i][1],dp[p][0] + 1);
			}	
		}
		dp[i][0] = max(max(dp[i][0],dp[i+1][0]),dp[i+1][1]);
	} 
	printf("%d",max(dp[0][1],dp[0][0]));
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n;
int k;
int a[N];
int dp[N];

int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin>>n>>k;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin>>a[i];
	}
	/*
	for(int i = 1 ; i <= n ; i ++)
	{
		dp[i] = dp[i - 1];
		if(a[i] == k)
		{
			dp[i] = max(dp[i] , dp[i - 1] + 1);
			cnt = i;
		}
		else
		{
			int temp = a[cnt + 1];
			for(int j = cnt + 2 ; j <= i ; j ++)
			{
				temp ^= a[j];
			}
			if(temp == k)
			{
				cnt = i;
				dp[i]= max(dp[i] , dp[i - 1] + 1);
			}
		}
	}
	*/
	for(int i = 1 ; i <= n ; i ++)
	{
		int temp = a[i];
		bool flag = 0;
		for(int j = i - 1 ; j >= 0 ; j --)
		{
			if(temp == k)
			{
				dp[i] = max(dp[i - 1] , dp[j] + 1);
				flag = 1;
				break;
			}
			temp ^= a[j];	
		}
		if(!flag)
		{
			dp[i] = dp[i - 1];
		}
	}
	cout<<dp[n];
	return 0;
	fclose(stdin);
	fclose(stdout);
}

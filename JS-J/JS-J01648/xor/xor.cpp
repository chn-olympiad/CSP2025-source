#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
int n,k,sum=0;
int a[N],c[N][N],dp[N][N];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	if(n>=(int)1e4)
	{
		if(k==1)
		{
			for(int i=1; i<=n; i++)
			{
				if(a[i]==1)    sum++;
			}
		}
		else if(k==0)
		{
			for(int i=1; i<n; i++)
			{
				if(a[i]==1 && a[i+1]==1)
				{
					sum++;
					i++;
				}
				else if(a[i]==0)	sum++;
			}
			if(!a[n])	sum++;
		}
		cout << sum << endl;
		return 0;
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=i; j<=n; j++)
		{
			c[i][j] = a[j]^c[i][j-1];
			if((a[j]^c[i][j-1])==k)    dp[i][j] = 1;
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=i; j<=n; j++)
		{
			dp[i][j] = max({dp[i-1][j-1]+dp[i][j], dp[i-1][j], dp[i][j-1]});
		}
	}
	cout << dp[n][n] << endl;
	return 0;
}

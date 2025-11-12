#include<bits/stdc++.h>
using namespace std;
int n,a[10001],ans;
struct note
{
	int maxx;
	int sum;
}dp[1001][1001];
int summ(int i,int j)
{
	int num=0;
	for(int k=i;k<=j;k++)
	{
		num+=a[k];
	}
	return num;
}
int maxn(int i,int j)
{
	int maxxx=-10000;
	for(int k=i;k<=j;k++)
	{
		if(a[k]>maxxx)
		{
			maxxx=a[k];
		}
	}
	return 2*maxxx;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		dp[i][i].sum=a[i];
		dp[i][i].maxx=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			dp[i][j].sum=dp[i][j-1].sum+a[j];
			dp[i][j].maxx=max(dp[i][j-1].maxx,a[j]);
			if(dp[i][j].sum>2*dp[i][j].maxx)
			{
				ans++;
				ans%=998244353;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=i+1;k<=j-1;k++)
			{
				for(int l=k;l<=j-1;l++)
				{
					if(dp[i][j].sum-dp[k][l].sum>2*dp[i][j].maxx)
					{
						ans++;
						ans%=998244353;
					}
				}	
			}
		}
	}
	cout<<ans;
	return 0;
}

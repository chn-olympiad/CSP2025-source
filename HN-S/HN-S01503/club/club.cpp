#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005][5];
int dp[105][105][105];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		memset(dp,0,sizeof(dp));
		for(int s=1;s<=n;s++)
		{
			for(int i=n/2;i>=0;i--)
			{
				for(int j=n/2;j>=0;j--)
				{
					for(int k=n/2;k>=0;k--)
						if(i+j+k<=n)
						{
							if(i>0)
								dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[s][1]);
							if(k>0)
								dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[s][3]);
							if(j>0)
								dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[s][2]);
						}
				}
			}
		}
		int maxv=0;
		for(int i=n/2;i>=0;i--)
		{
			for(int j=n/2;j>=0;j--)
			{
				for(int k=n/2;k>=0;k--)
				{
					if(i+j+k<=n)
					{
						maxv=max(maxv,dp[i][j][k]);
					}
				}
			}
		}
		cout<<maxv<<endl;
	}
	return 0;
} 

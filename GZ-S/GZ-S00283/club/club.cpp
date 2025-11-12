#include<bits/stdc++.h>
using namespace std;
int a[1001][3];
int dp[1001][3];
int ansx[1001];
int kx[3]={1,1,1};
int z=0;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
			}
		}
		int c1=0,c2=0,c3=0;
		for(int i=0;i<3;i++) dp[0][i]=a[0][i];
		for(int i=1;i<n;i++)
		{
			if(c1==n/2) kx[0]=0;
			if(c2==n/2) kx[1]=0;
			if(c3==n/2) kx[2]=0;
			for(int j=0;j<3;j++)
			{
				if(kx[j]!=0)
				{
					for(int x=0;x<3;x++)
					{
						if(kx[x]!=0)
						{
							dp[i][j]=max(dp[i][j],dp[i-1][x]+a[i][j]);
							cout<<dp[i][j]<<" ";
							if(dp[i][j]==dp[i-1][0]+a[i][j]) c1++;
							if(dp[i][j]==dp[i-1][1]+a[i][j]) c2++;
							if(dp[i][j]==dp[i-1][2]+a[i][j]) c3++;
						}
						cout<<endl;
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<n;i++) if(dp[n][i]>ans) ans=dp[n][i];
		ansx[z++]=ans;
	}
	for(int i=0;i<z;i++) cout<<ansx[i];
	return 0;
}

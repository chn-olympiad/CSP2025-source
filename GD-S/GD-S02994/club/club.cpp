#include<bits/stdc++.h>
using namespace std;
int t,f[10005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++)
	{
		int n,a[10005][4];
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		long long dp[1005][1005];
		if(n<=2)
		{
			int h[10005];
			int h1,h2,h3;
			h1=a[1][1]+max(a[2][2],a[2][3]);
			h2=a[1][2]+max(a[2][1],a[2][3]);
			h3=a[1][3]+max(a[2][1],a[2][2]);
			f[l]=max(h1,max(h2,h3));
			continue;
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=n/2;j++)
			{
				for(int k=1;k<=n;k++)
				{
					dp[i][j]=dp[i][j-1];
					dp[i][j]=max(dp[i][j],dp[i][j-1]+a[k][i]);
				}
			}
		}
		f[l]+=dp[1][n/2]+dp[2][n/2]+dp[3][n/2]; 
		
	}	
	for(int i=1;i<=t;i++)
	cout<<f[i]<<endl;
}

#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1100],dp[110][110]={};
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	int tot=0;
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==ans)
		{
			tot=i;
			break;
		}
	}
	dp[1][1]=1;
	for (int i=1;i<=m;i++)
	{
		if (i==1) continue;
		if (i%2==0) dp[1][i]=dp[1][i-1]+2*n-1;
		else dp[1][i]=dp[1][i-1]+1;
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (j%2==0) dp[i][j]=dp[i-1][j]-1;
			else dp[i][j]=dp[i-1][j]+1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (dp[i][j]==tot)
			{
				cout<<j<<" "<<i<<endl;
				return 0;	
			}
		}
	}
	return 0;
}

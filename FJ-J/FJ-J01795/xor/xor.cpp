#include<bits/stdc++.h>
using namespace std;
int xx[100];
int yy[100];
int ans[100];
struct node
{
	int q,h;
}b[100000];
int xoor(int x,int y)
{
	int ii=1;
	while(x>0)
	{
		xx[ii]=x%2;
		ii++;
		x/=2;
	}
	int jj=1;
	while(y>0)
	{
		yy[jj]=y%2;
		jj++;
		y/=2;
	}
	for(int i=1;i<max(ii,jj);i++)
	{
		ans[i]=xx[i]!=yy[i];
	}
	int s=0;
	for(int i=max(ii,jj)-1;i>=1;i--)
	{
		s*=2;
		s+=ans[i];
	}
	return s;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+10];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		if(a[1]==k)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	if(n==2)
	{
		if(a[1]==k&&a[2]==k)
		{
			cout<<2;
			return 0;
		}
		if(a[1]!=k&&a[2]!=k&&xoor(a[1],a[2])==k)
		{
			cout<<1;
			return 0;
		}
		if(a[1]!=k&&a[2]!=k&&xoor(a[1],a[2])!=k)
		{
			cout<<0;
			return 0;
		}
		if(xoor(a[1],a[2])!=k)
		{
			cout<<2;
			return 0;
		}
	}
	int dp[n+10][n+10];
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			dp[j][i]=xoor(dp[j+1][i],a[j]);
		}
	}
	int l=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(dp[i][j]==k)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

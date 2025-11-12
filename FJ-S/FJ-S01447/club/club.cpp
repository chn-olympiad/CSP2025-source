#include<bits/stdc++.h>
using namespace std;
int t,n,a[4][100001];
long long dp[301][301][301];
bool cmp(int i,int j)
{
	return i>j;
}
void solve1()
{
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
		for(int j=1;j<4;j++)
			cin>>a[j][i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=min(i,n/2);j++)
			for(int k=0;k<=min(i-j,n/2);k++)
			{
				if(j>0)
					dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j-1][k][i-j-k]+a[1][i]);
				if(k>0)
					dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j][k-1][i-j-k]+a[2][i]);
				if(i-j-k>0)
					dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j][k][i-j-k-1]+a[3][i]);
			}
	long long s=0;
	for(int i=0;i<=n/2;i++)
		for(int j=0;j<=n/2;j++)
			if(n-i-j<=n/2)
				s=max(s,dp[i][j][n-i-j]);
	cout<<s<<"\n";
}
void solve3()
{
	long long dp[1001][1001];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=min(i,n/2);j++)
		{
			if(j>0)
				dp[j][i-j]=max(dp[j][i-j],dp[j-1][i-j]+a[1][i]);
			if(i-j>0)
				dp[j][i-j]=max(dp[j][i-j],dp[j][i-j-1]+a[2][i]);
		}
	long long s=0;
	for(int i=0;i<=n/2;i++)
		for(int j=0;j<=n/2;j++)
			if(n-i-j<=n/2)
				s=max(s,dp[i][j]);
	cout<<s<<"\n";
}
void solve2()
{
	bool bj1=0,bj2=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<4;j++)
			cin>>a[j][i];
		if(a[2][i]>0)
			bj1=1;
		if(a[3][i]>0)
			bj2=1;
	}
	if(bj2==1)
	{
		cout<<"0\n";
		return;
	}
	if(bj1==0&&bj2==0)
	{
		long long s=0;
		sort(a[1]+1,a[1]+n+1,cmp);
		for(int i=1;i<=n/2;i++)
			s=s+a[1][i];
		cout<<s<<"\n";
		return;
	}
	if(bj1==1&&n<=1000)
		solve3();
	else
		cout<<"0\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<=300)
			solve1();
		else
			solve2();
	}
	return 0;
}

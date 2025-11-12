#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
int a[N][4];
void solve1()
{
	int dp[201][201][201]={};
	for(int i=1;i<=n;i++)
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=min(i,n/2);j++)
			for(int k=0;k<=min(i,n/2);k++)
			{
				int l=i-j-k;
				if(l<0 || l>n/2) continue;
				if(j>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
				if(k>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
				if(l>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
			}
	int ans=0;
	for(int i=0;i<=n/2;i++)
		for(int j=0;j<=n/2;j++)
		{
			int k=n-i-j;
			if(k<0 || k>n/2) continue;
			ans=max(ans,dp[n][i][j]);
		}
	printf("%d\n",ans);
}
bool cmp(int x,int y)
{
	return x>y;
}
void solve3()
{
	int s[N]={};
	for(int i=1;i<=n;i++)
		s[i]=a[i][1];
	sort(s+1,s+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n/2;i++)
		ans+=s[i];
	printf("%d\n",ans);
}
void solve2()
{
	bool flag1=1,flag2=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]) flag1=0;
		if(a[i][3]) flag2=0;
	}
	if(flag1)
	{
		solve3();
		return;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n<=200) solve1();
		else solve2();
	}
	return 0;
}

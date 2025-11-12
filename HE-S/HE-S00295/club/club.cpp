#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int t;
int n;
struct op
{
	int bh,jf;
}a[4][N];
bool ok(op x,op y)
{
	return x.jf>y.jf;
}
bool bok[N][4];
int ans[4];
int dp[N][10][4],b[4][N];
bool okk(op x,op y)
{
	return x.bh<y.bh;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>t;
while(t--)
{
	cin>>n;
	for(int i=1;i<=1e5;i++)
	{
		
		for(int j=1;j<=3;j++)
		{
			b[j][i]=0;
			a[j][i].bh=0;
			a[j][i].jf=0;
			bok[i][j]=0;
			for(int k=1;k<=3;k++)
			{
				dp[i][j][k]=0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[j][i].jf;
			a[j][i].bh=i;
			ans[j]=0;
		}
	}
	int s=0;
	int ansx;
	for(int i=1;i<=3;i++)
	{
		sort(a[i]+1,a[i]+n+1,ok);
		for(int j=1;j<=n/2;j++)
		{
			ans[i]+=a[i][j].jf;
			bok[a[i][j].bh][i]=1;
		}
	}
	for(int i=1;i<=3;i++)
	{
		sort(a[i]+1,a[i]+n+1,okk);
	}
	int cnt=0;
	int ansss=0;
	for(int i=1;i<=n;i++)
	{
		if(!bok[i][3])
		{
			dp[i][1][3]=max(dp[i-1][2][3]+a[1][i].jf,dp[i][1][3]);
			dp[i][2][3]=max(dp[i-1][2][3]+a[2][i].jf,dp[i][1][3]);
		}
		if(!bok[i][2])
		{
			dp[i][1][2]=max(dp[i-1][3][2]+a[1][i].jf,dp[i][1][2]);
			dp[i][3][2]=max(dp[i-1][3][2]+a[3][i].jf,dp[i][1][2]);
		}
		if(!bok[i][1])
		{
			dp[i][2][1]=dp[i-1][3][1]+a[2][i].jf;
			dp[i][3][1]=max(dp[i-1][3][1]+a[3][i].jf,dp[i][2][1]);
		}
		
	}
	ansss=max(max(max(dp[n][3][1]+ans[1],dp[n][3][2]+ans[2]),dp[n][2][3]+ans[3]),ansss);
	cout<<ansss<<endl;
}
	return 0;
} 

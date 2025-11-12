#include<bits/stdc++.h>
using namespace std;
int T,n,ans,dp[35][16][16][16],f[205][105][105],flag=1;
struct node{
	int a,b,c;
}a[100005];
bool cmp(node a,node b){return a.a>b.a;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;memset(dp,0,sizeof(dp));memset(f,0,sizeof(f));flag=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x,y,z;cin>>x>>y>>z;
			a[i].a=x;a[i].b=y;a[i].c=z;if(z!=0) flag=0;
		}
		if(n<=30)
		{
			for(int i=1;i<=n;i++)
			for(int j=0;j<=i;j++)
			for(int k=0;k<=i;k++)
			for(int l=0;l<=i;l++)
			{
				if(j+k+l>i) continue;
				if(l>n/2||k>n/2||j>n/2) continue;
				if(j-1>=0) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j-1][k][l]+a[i].a);
				if(k-1>=0) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k-1][l]+a[i].b);
				if(l-1>=0) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l-1]+a[i].c);
			}
			for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
			ans=max(ans,dp[n][i][j][k]);
		}
		if(n>30&&n<=200&&flag)
		{
			for(int i=1;i<=n;i++)
			for(int j=0;j<=i;j++)
			for(int k=0;k<=i;k++)
			{
				if(j+k>i) continue;
				if(k>n/2||j>n/2) continue;
				if(j-1>=0) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i].a);
				if(k-1>=0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].b);
			}
			for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
			ans=max(ans,f[n][i][j]);
		}
		if(n>200)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].a;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
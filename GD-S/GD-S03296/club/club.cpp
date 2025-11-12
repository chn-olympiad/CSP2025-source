#include<bits/stdc++.h>
using namespace std;
int t,n,a[110000][5],dp[210][210][210];
struct ll
{
	int x,y,z;
}b[110000];
bool cmp1(ll a,ll b)
{
	return a.x>b.x||a.x==b.x&&a.y>b.y||a.x==b.x&&a.y==b.y&&a.z>b.z;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		int ma=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		if(n<300)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=i-1;j++)
				{
					for(int k=0;k<=i-1;k++)
					{
						int l=i-1-j-k;
						if(l<0)continue;
						dp[j+1][k][l]=max(dp[j+1][k][l],dp[j][k][l]+a[i][1]);
						dp[j][k+1][l]=max(dp[j][k+1][l],dp[j][k][l]+a[i][2]);
						dp[j][k][l+1]=max(dp[j][k][l+1],dp[j][k][l]+a[i][3]);
						if(i==n)
						{
							if(j+1<=i/2&&k<=i/2&&l<=i/2)ma=max(ma,dp[j+1][k][l]);
							if(j<=i/2&&k+1<=i/2&&l<=i/2)ma=max(ma,dp[j][k+1][l]);
							if(j<=i/2&&k<=i/2&&l+1<=i/2)ma=max(ma,dp[j][k][l+1]);
						}
					}
				}
			}
			printf("%d\n",ma);
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			b[i].x=a[i][1];
			b[i].y=a[i][2];
			b[i].z=a[i][3];
		}
		sort(b+1,b+1+n,cmp1);
		int s1=0;
		for(int i=1;i<=n/2;i++)s1+=b[i].x;
		for(int i=n/2+1;i<=n;i++)s1+=b[i].y;
		printf("%d\n",s1);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
*/

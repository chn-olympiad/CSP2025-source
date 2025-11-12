#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],n,T,dp[101][101][101],dpa[205][205],ans=0,o=0,q=0;
bool flaa=false,flab=false;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		ans=0;
		scanf("%d",&n);
		flaa=false;
		flab=false;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(c[i]!=0)
			flab=true;
			if(b[i]!=0||c[i]!=0)
			flaa=true;
			o=max(a[i],o);
			q=max(b[i],q);
		}
		if(flaa==false)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i];
			}
			printf("%d\n",ans);
			continue;
		}
		if(flaa==true&&flab==false&&n==200)
		{
			for(int p=1;p<=n;p++)
			{
				for(int i=n/2;i>=1;i--)
				{
					for(int j=n/2;j>=1;j--)
					{
						dpa[1][0]=o;
						dpa[0][1]=q;
						dpa[i][j]=max(dpa[i-1][j]+a[i],dpa[i][j-1]+b[i]);
						ans=max(ans,dpa[i][j]);
					}
				}
			}
			printf("%d\n",ans);
			continue;
		}
		if(flaa==true&&flab==true)
		{
			for(int p=1;p<=n;p++)
			{
				for(int i=n/2;i>=0;i--)
				{
					for(int j=n/2;j>=0;j--)
					{
						for(int k=n/2;k>=0;k--)
						{
							if(i>=1&&j>=1&&k>=1)
							dp[i][j][k]=max(dp[i][j][k],max(max(dp[i-1][j][k]+a[p],dp[i][j-1][k]+b[p]),dp[i][j][k-1]+c[p]));
							if(i>=1&&j>=1&&k==0)
							dp[i][j][k]=max(dp[i][j][k],max(dp[i-1][j][k]+a[p],dp[i][j-1][k]+b[p]));
							if(i>=1&&j==0&&k>=1)
							dp[i][j][k]=max(dp[i][j][k],max(dp[i-1][j][k]+a[p],dp[i][j][k-1]+c[p]));
							if(i==0&&j>=1&&k>=1)
							dp[i][j][k]=max(dp[i][j][k],max(dp[i][j-1][k]+b[p],dp[i][j][k-1]+c[p]));
							if(i==0&&j==0&&k>=1)
							dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+c[p]);
							if(i==0&&j>=1&&k==0)
							dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+b[p]);
							if(i>=1&&j==0&&k==0)
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[p]);
							if(i==0&&j==0&&k==0)
							dp[i][j][k]=0;
							ans=max(ans,dp[i][j][k]);
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

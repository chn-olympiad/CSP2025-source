#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int in()
{
	int ans=0,ff=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
	{
		if(c=='-')
		{
			ff*=-1;
		}
	}
	for(;isdigit(c);c=getchar())
	{
		ans=ans*10+c-'0';
	}
	return ans*ff;
}
void out(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x>=10)
	{
		out(x/10);
	}
	putchar(x%10+'0');
}
int T;
int n;
int a[N][10];
int aa[N];
int dp[210][210][210][10];
int bb[N];
bool fg1=1;
bool fg2=1;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=in();
	while(T--)
	{
		memset(a,0,sizeof a);
		memset(aa,0,sizeof aa);
		memset(dp,0,sizeof dp);
		memset(bb,0,sizeof bb);
		n=in();
		for(int i=1;i<=n;i++)
		{
			a[i][1]=in(),a[i][2]=in(),a[i][3]=in();
			aa[i]=a[i][1];
			bb[i]=a[i][1]-a[i][2];
			if(a[i][2]!=0||a[i][3]!=0)
			{
				fg1=0;
			}
			if(a[i][3]!=0)
			{
				fg2=0;
			}
		}
		if(n<=200)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=min(i,n/2);j++)
				{
					for(int k=0;k<=min(i-j,n/2);k++)
					{
						int t=i-j-k;
						if(t>n/2)
						{
							continue;
						}
						if(j>=1)
						{
							dp[i][j][k][1]=max(dp[i][j][k][1],dp[i-1][j-1][k][1]+a[i][1]);
							dp[i][j][k][1]=max(dp[i][j][k][1],dp[i-1][j-1][k][2]+a[i][1]);
							dp[i][j][k][1]=max(dp[i][j][k][1],dp[i-1][j-1][k][3]+a[i][1]);
						}
						if(k>=1)
						{
							dp[i][j][k][2]=max(dp[i][j][k][2],dp[i-1][j][k-1][1]+a[i][2]);
							dp[i][j][k][2]=max(dp[i][j][k][2],dp[i-1][j][k-1][2]+a[i][2]);
							dp[i][j][k][2]=max(dp[i][j][k][2],dp[i-1][j][k-1][3]+a[i][2]);
						}
						if(t>=1)
						{
							dp[i][j][k][3]=max(dp[i][j][k][3],dp[i-1][j][k][1]+a[i][3]);
							dp[i][j][k][3]=max(dp[i][j][k][3],dp[i-1][j][k][2]+a[i][3]);
							dp[i][j][k][3]=max(dp[i][j][k][3],dp[i-1][j][k][3]+a[i][3]);
						}
					}
				}
			}
			int ans=0;
			for(int i=0;i<=n/2;i++)
			{
				for(int k=0;k<=min(n-i,n/2);k++)
				{
					if(n-i-k<=n/2)
					{
						for(int j=1;j<=3;j++)
						{
							ans=max(ans,dp[n][i][k][j]);
						}
					}
				}
			}
			out(ans);
			puts("");
		}
		else
		{
			if(fg1)
			{
				sort(aa+1,aa+1+n,cmp);
				int ans=0;
				for(int i=1;i<=n/2;i++)
				{
					ans+=aa[i];
				}
				out(ans);
				puts("");
			}
			else if(fg2)
			{
				sort(bb+1,bb+1+n);
				int ans=0;
				for(int i=1;i<=n;i++)
				{
					ans+=a[i][1];
				}
				for(int i=1;i<=n/2;i++)
				{
					ans-=bb[i];
				}
				out(ans);
				puts("");
			}
			else
			{
				int ans=0;
				for(int i=1;i<=n/2;i++)
				{
					ans+=a[i][1];
				}
				for(int i=n/2+1;i<=n;i++)
				{
					ans+=a[i][2];
				}
				out(ans);
				puts("");
			}
		}
	}
	return 0;
}


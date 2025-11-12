#include<bits/stdc++.h>
//#define int long long
#define INF 0x3f3f3f3f
using namespace std;
int n,m,a[514191],b[514191],c[514191],dp[514191],ans,mx;
int dpx[202511][260];
void solve1() //n<=1e3
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((b[j]^b[i-1])==m)
			{
				c[i]=j;
				break;
			}
		}
	}
	dp[n]=c[n];
	for(int i=n-1;i>=1;i--)
	{
		dp[i]=min(dp[i+1],c[i]);
	}
	if(dp[1]>n)
	{
		printf("0\n");
		return;
	}
	for(int i=1;i<=n;i=dp[i]+1)
	{
		if(dp[i]+1<=n)
		{
			ans++;
		}
	}
	printf("%d\n",ans);
}
void solve2() //n<=2e5&&k<=255
{
	memset(dpx,INF,sizeof(dpx));
	for(int i=1;i<=n;i++)
	{
		dpx[i][a[i]]=i;
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=0;j<=255;j++)
		{
			dpx[i][j]=min(dpx[i][j],dpx[i+1][j^a[i]]);
		}
	}
	for(int i=1;i<=n;)
	{
		int mn=INF;
		for(int j=0;j<=255;j++)
		{
			if(dpx[i][j]+1<=n)
			{
				mn=min(mn,dpx[dpx[i][j]+1][j^m]);
			}
		}
		if(mn<=n)
		{
			ans++;
			i=mn+1;
		}
		else
		{
			break;
		}
	}
	printf("%d\n",ans);
}
void solve3() //k<=1
{
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	else
	{
		for(int i=1,j=0;i<=n;i++)
		{
			if(a[i]==0)
			{
				ans++;
				j=0;
			}
			else
			{
				j++;
				if(j%2==0)
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(c,INF,sizeof(c));
	memset(dp,INF,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		b[i]=(b[i-1]^a[i]);
		mx=max(mx,a[i]);
	}
	if(n<=1000)
	{
		solve1();
	}
	else
	{
		if(mx<=1)
		{
			solve3();
		}
		else
		{
			solve2();
		}
	}
	return 0;
}
/*O(n^2),65pts*/

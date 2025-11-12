#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int N=200;
int dp[N][N][N];
int T,n,n2,maxn;
struct Node{
	int a1;
	int a2;
	int a3;
}ed[N];
bool A,B;
bool cmp(Node x,Node y)
{
	return x.a1>y.a1;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		maxn=0;
		A=B=false;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld %lld %lld",&ed[i].a1,&ed[i].a2,&ed[i].a3);
			if(ed[i].a3!=0)A=true;
			if(ed[i].a3!=0||ed[i].a2!=0)B=true;
		}
		n2=n/2;
		if(!B)
		{
			sort(ed+1,ed+n+1,cmp);
			for(int i=1;i<=n2;i++)
			{
				maxn+=ed[i].a1;
			}
			printf("%lld\n",maxn);
			continue;
		}
//		else if(!A)
//		{
//			int dp2[N][5];
//			memset(dp2,0,sizeof(dp2));
//			for(int i=1;i<=n;i++)
//			{
//				dp2[i][1]=max(dp[i-1][1])
//			}
//		}
		for(int i=0;i<=n2;i++)
		{
			for(int j=0;j<=n2;j++)
			{
				for(int k=0;k<=n2;k++)
				{
					if(i+j+k>n)continue;
					if(i-1>=0)dp[i][j][k]=max(dp[i-1][j][k]+ed[i+j+k].a1,dp[i][j][k]);
					if(j-1>=0)dp[i][j][k]=max(dp[i][j-1][k]+ed[i+j+k].a2,dp[i][j][k]);
					if(k-1>=0)dp[i][j][k]=max(dp[i][j][k-1]+ed[i+j+k].a3,dp[i][j][k]);
					if(i+j+k==n)
					{
						maxn=max(maxn,dp[i][j][k]);
						continue;
					}
				}
			}
		}
			printf("%lld\n",maxn);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

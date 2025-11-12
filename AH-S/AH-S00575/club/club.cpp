#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100001
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
struct Freshman
{
	int x,y,z;
	bool operator < (const Freshman &a) const&
	{
		return a.x-a.y<x-y;
	}
}a[N];
int T,n,dp[101][101][2],ans;
void Work1()
{
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=min(i,n>>1);++j)
		{
			for(int k=0;k<=min(i,n>>1);++k)
			{
				int l=i-j-k;
				if(l>=0&&l<=n>>1)
				{
					if(j)dp[j][k][l&1]=dp[j-1][k][l&1]+a[i].x;
					if(k)dp[j][k][l&1]=max(dp[j][k][l&1],dp[j][k-1][l&1]+a[i].y);
					if(l)dp[j][k][l&1]=max(dp[j][k][l&1],dp[j][k][(l&1)^1]+a[i].z);
					ans=max(dp[j][k][l&1],ans);
//					printf("DEBUG:%3d%3d%3d%3d%3d%3d\n",i,j,k,l,dp[j][k][l&1],ans);
				}
			}
		}
	}
	printf("%d\n",ans);
}
void Work2()
{
	std::stable_sort(a+1,a+n+1);
	for(int i=1;i<=n>>1;++i)
		ans+=a[i].x+a[n-i+1].y;
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
//		for(int i=1;i<=n;++i)
//			printf("DEBUG: %d %d %d\n",a[i].x,a[i].y,a[i].z);
		ans=0;
		if(n<=200)Work1();//n<=200
		else Work2();//A,B Sp.
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
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long int 
using namespace std;
const int N=1e5;
ll a[N+5][5],b[5][N+5];
int f[N+5],g[N+5];
bool cmp(int x,int y)
{
	return (a[x][f[x]]+a[y][g[y]])>(a[x][g[x]]+a[y][f[y]]);
}
void slv()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<3;i++)
	{
		b[i][0]=0;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=g[i]=3;
		for(int j=0;j<3;j++)
		{
			scanf("%lld",&a[i][j]);
			if(a[i][j]>=a[i][f[i]])
			{
				f[i]=j;
			}
		}
		for(int j=0;j<3;j++)
		{
			if((j!=f[i])&&(a[i][j]>=a[i][g[i]]))
			{
				g[i]=j;
			}
		}
		b[f[i]][++b[f[i]][0]]=i;
	}
	for(int i=0;i<3;i++)
	{
		if(b[i][0]>(n/2))
		{
			sort(b[i]+1,b[i]+b[i][0]+1,cmp);
			for(int j=(n/2)+1;j<=b[i][0];j++)
			{
				f[b[i][j]]=g[b[i][j]];
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i][f[i]];
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		slv();
	}
	return 0;
}

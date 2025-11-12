//GZ-S00109 毕节七星关东辰实验学校 周泰丞
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
bool vis[10020]{false};
struct point{
	long long to;
	long long w;
};
vector<point> tree[10020];
long long n,m,k,ans=10e9+1;
long long dfs(long long x,long long y,long long from)
{
	y++;
	if(vis[x])
	{
		y--;
		return 10e9+1; 
	}
	printf("%d->%d w=%d    ",from,x,tree[x][from].w);
	vis[x]=true;
	if(y==n)
	{
		vis[x]=false;
		y--;
		return tree[x][from].w;
	}
	long long aans=10e9+1;
	for(int i=0;i<=tree[x].size()-1;i++)
	{
		aans=min(aans,dfs(tree[x][i].to,y,x));
	}
	y--;
	vis[x]=false;
	return aans+tree[from][x].w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		point p;
		p.to=b;
		p.w=c;
		tree[a].push_back(p);
		p.to=a;
		tree[b].push_back(p);
	}
	for(long long i=1;i<=k;i++)
	{
		long long cun[n+1],jia;
		scanf("%lld",&jia);
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld",&cun[i]);
		}
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i;j<=n;j++)
			{
				point p;
				p.to=j;
				p.w=cun[i]+cun[j]+jia;
				tree[i].push_back(p);
				p.to=i;
				tree[j].push_back(p);
			}
		}
	}
	for(int i=0;i<=tree[1].size()-1;i++)
	{
		ans=min(ans,dfs(tree[1][i].to,0,1)+tree[1][i].w);
	}
	printf("%lld",ans);
	return 0;
} 

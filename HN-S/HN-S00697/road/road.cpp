#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int N=1e+3+5,M=1e+6+5;
int n,m,k,f[N*10],id;
long long c[11],Map[11][N],Map1[N][N];
struct edge
{
	int u,v;
	long long w;
}e[M],e1[N*N];

bool cmp(edge a,edge b)
{
	return a.w<b.w;
}

void init()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&Map[i][j]);
	}
}

void add(int u,int v,long long w)
{
	id++; e1[id].u=u;
	e1[id].v=v; e1[id].w=w;
}

long long getin(int x)
{
	int z=1; id=0;
	bool flag[11];
	long long ans=0;
	memset(Map1,0x3f,sizeof(Map1));
	while (x>0)
	{
		flag[z]=(x&1);
		if(x&1)
		{
			if(z<=k)
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					Map1[i][j]=min(Map1[i][j],Map[z][i]+Map[z][j]);
		}
		z++; x=(x>>1);
	}
	for(int i=1;i<=m;i++) Map1[e[i].u][e[i].v]=Map1[e[i].v][e[i].u]=min(Map1[e[i].u][e[i].v],e[i].w);
	for(int i=1;i<=k;i++) if(flag[i]) ans+=c[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(i!=j && Map1[i][j]<=1000000000){add(i,j,Map1[i][j]);}
	sort(e1+1,e1+id+1,cmp);
	return ans;
}

int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}

long long calc()
{
	long long ans=0;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1,num=0;i<=id && num<n;i++)
	{
		int fa=find(e1[i].u),fb=find(e1[i].v);
		if(fa==fb)continue;
		f[fa]=fb; num++; ans+=e1[i].w;
	}
	return ans;
}

long long calc1()
{
	long long ans=0;
	for(int i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1,num=0;i<=m && num<n;i++)
	{
		int fa=find(e[i].u),fb=find(e[i].v);
		if(fa==fb)continue;
		f[fa]=fb; num++; ans+=e[i].w;
	}
	return ans;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	if(k==0) printf("%lld",calc1());
	else
	{
		long long ans=1e+16;
		for(int i=(1<<k);i>=0;i--)
		{
			long long tx=getin(i);
			ans=min(ans,tx+calc());
		}
		printf("%lld",ans);
	}
	return 0;
}

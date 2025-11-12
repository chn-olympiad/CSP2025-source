#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,c[15],a[15][10005],f[10015];
long long ans=9e18;
struct node
{
	int u,v,w;
}e[2000005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(f[x]!=x)
		return find(f[x]);
	return f[x];
}
void merge(int x,int y)
{
	f[find(x)]=find(y);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf ("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++)
		scanf ("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	for (int i=1;i<=k;i++)
	{
		scanf ("%d",&c[i]);
		for (int j=1;j<=n;j++)
			scanf ("%d",&a[i][j]);
	}
	for (int i=0;i<(1<<k);i++)
	{
		int cnt=m;
		long long sum=0;
		for (int j=1;j<=n+k;j++)
			f[j]=j;
		for (int j=1;j<=k;j++)
			if(i&(1<<j-1))
			{
				for (int x=1;x<=n;x++)
					e[++cnt]=(node){x,j+n,a[j][x]};
				sum+=c[j];
			}
		sort(e+1,e+1+cnt,cmp);
		for (int j=1;j<=cnt;j++)
			if(find(e[j].u)!=find(e[j].v))
			{
				merge(e[j].u,e[j].v);
				sum+=e[j].w;
			}
		ans=min(ans,sum);
	}
	printf ("%lld",ans);
	return 0;
}

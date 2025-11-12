#include<cstdio>
#include<algorithm>
#define N 10005
#define M 2000005
using namespace std;
int n,m,k;
long long ans;
int up[N],cs[15][N];
int use[15],fuse[15];
struct edge
{
	int f,t,d;
}ed[M];
int f[N];
bool cmp(edge eda,edge edb)
{
	if(eda.d==edb.d)return eda.t<edb.t;
	return eda.d<edb.d;
}
int find(int x)
{
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
bool family(int x,int y)
{
	return find(x)==find(y);
}
void craft(int x,int y)
{
	f[find(y)]=find(x);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&ed[i].f,&ed[i].t,&ed[i].d);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&cs[i][0]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&cs[i][j]);
			ed[++m]={j,n+i,cs[i][j]};
		}
	}
	sort(ed+1,ed+m+1,cmp);
	int j=0,nw=n;
	for(int i=1;j<nw-1&&i<=m;i++)
	{
		if(!family(ed[i].f,ed[i].t))
		{
			craft(ed[i].f,ed[i].t);
			ans+=ed[i].d;
			if(ed[i].t>n)
			{
				if(!use[ed[i].t-n])
				{
					nw++;
					fuse[ed[i].t-n]=i;
					ans+=cs[ed[i].t-n][0];
				}
				use[ed[i].t-n]++;
			}
		}
	}
	for(int i=1;i<=k;i++)
		if(use[k]==1)
			ans-=ed[fuse[k]].d+cs[k][0];
	printf("%d",ans);
}

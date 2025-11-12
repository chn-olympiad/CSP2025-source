#include<algorithm>
#include<cstdio>
#define int long long
#define MIN(x,y) ((x)<(y)?(x):(y))
using namespace std;
int n,m,k,ans;
struct str
{
	int u,v,w;
}ro[1000001];
int c[11],a[11][10001];
int fa[10001];
bool city[11];
int find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void add(int x,int y)
{
	x=find(x),y=find(y);
	fa[y]=x;
}
auto cmp=[](str x,str y){return x.w<y.w;};
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&ro[i].u,&ro[i].v,&ro[i].w);
	}
	for(int i=0;i<k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	sort(ro,ro+m,cmp);
	for(int i=0;i<m;i++)
	{
		if(find(ro[i].u)!=find(ro[i].v))
		{
			add(ro[i].u,ro[i].v);
			int mi=1e9;
			for(int j=0;j<k;j++)
			{
				int obj;
				if(!city[j]) obj=c[j];
				else obj=0;
				city[j]=true;
				mi=MIN(mi,obj+a[j][ro[i].u]+a[j][ro[i].v]);
			}
			ans+=MIN(mi,ro[i].w);
		}
	}
	printf("%lld",ans);
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
const int M=2e7+7;
int n,m,k,c,cnt=0,lan=0;
long long sum=0;
int fa[N],a[N];
struct op{int u,v,w;}way[M];
bool cmp(op x,op y)
{
	if(x.w<=y.w)return true;
	return false;
}
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
		fa[i]=i;
	for(i=1;i<=m;i++)
	{
		cnt++;
		scanf("%d%d%d",&way[cnt].u,&way[cnt].v,&way[cnt].w);
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d",&c);
		for(j=1;j<=n;j++)
			scanf("%d",&a[j]);
		for(j=1;j<n;j++)
			for(int l=j+1;l<=n;l++)
			{
				way[++cnt].u=j;way[cnt].v=l;
				way[cnt].w=a[j]+a[l]+c;
			}
	}
	sort(way+1,way+cnt+1,cmp);
	for(i=1;i<=cnt;i++)
	{
		fa[way[i].v]=find(fa[way[i].v]);
		fa[way[i].u]=find(fa[way[i].u]);
		if(fa[way[i].v]!=fa[way[i].u])
		{
			fa[way[i].u]=fa[way[i].v];
			sum+=way[i].w;lan++;
		}
		if(lan==n-1)break;
	}
	printf("%lld",sum);
	return 0;
}

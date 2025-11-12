#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1145141;
struct node{
	int u,v,w;
}t[N*10];
int c[N],a[20][114514],cnt;
bool cmp(node c,node d)
{
	return c.w<d.w;
}
int fa[N];
int find(int x)
{
	if(fa[x]==x)
	  return fa[x];
	return fa[x]=find(fa[x]);
}
void hb(int x,int y)
{
	fa[find(x)]=find(y);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	  fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		t[++cnt].u=u;
		t[cnt].v=v;
		t[cnt].w=w;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
		for(int j=1;j<=n;j++)
		{
			for(int e=j+1;e<=n;e++)
			{
				t[++cnt].u=j;
				t[cnt].v=e;
				t[cnt].w=a[i][j]+a[i][e];
			}
		}
	}
	sort(t+1,t+1+cnt,cmp);
	int sum=0;
	ll ans=0;
	for(int i=1;i<=cnt;i++)
	{
		if(find(t[i].u)!=find(t[i].v))
		{
			ans+=t[i].w;
			sum++;
			hb(t[i].u,t[i].v);
		}
		if(sum>=n-1)
		  break;
	}
	printf("%lld",ans);
	return 0;
 } //我要上人类迷惑行为大赏！*114514

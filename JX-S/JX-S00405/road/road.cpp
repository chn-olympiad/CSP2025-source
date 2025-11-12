#include<bits/stdc++.h>
using namespace std;
const int range=2e6+5;
int fa[range];
int n,m,len,k,cnt;
struct EID
{
	int u,v,w;
}e[range];
bool cmp(EID a,EID b){return a.w<b.w;}
long long ans;
int get_fa(int u)
{
	if(u==fa[u]) return u;
	return fa[u]=get_fa(fa[u]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[++len]={u,v,w};
	}
	for(int i=n+1;i<=n+k;i++)
	{
		int w;
		scanf("%d",&w);
		for(int j=1;j<=n;j++)
		{
			int w;
			scanf("%d",&w);
			e[++len]={i,j,w};
		}
	}
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(e+1,e+len+1,cmp);
	for(int i=1;i<=len;i++)
	{
		int u=e[i].u;
		int v=e[i].v;
		int w=e[i].w;
		int fu=get_fa(u);
		int fv=get_fa(v);
		if(fu==fv) continue;
		fa[fu]=fv;
		ans+=w;
		cnt++;
		if(cnt==n+k-1) break;
	}
	printf("%lld",ans);
	return 0;
}

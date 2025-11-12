#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+5;
int n,m,k,fa[N],ans,u,v,tot,c[N];
int read()
{
	int w=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') w=(w<<3)+(w<<1)+c-'0',c=getchar();
	return w*f;
}
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
struct node
{
	int u,v,w;
}a[N];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++) a[i].u=read(),a[i].v=read(),a[i].w=read();
	tot=m;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();ans+=c[i];
		for(int j=1;j<=n;j++) a[++tot].u=n+i,a[tot].v=j,a[tot].w=read();
	}
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=tot;i++)
	{
		u=find(a[i].u);v=find(a[i].v);
		if(u!=v) ans+=a[i].w,fa[v]=u;
	}
	printf("%lld",ans);
}

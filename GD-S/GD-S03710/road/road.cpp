#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define N 1000010
using namespace std;
inline long long read(){
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
int fa[N],n,m,k,c[N],vis[N];
int find(int x)
{
	if(fa[x]==x) return fa[x];
	else return fa[x]=find(fa[x]);
}
struct node{
	int u,v,w,id;
}e[N];
int cmp(node a,node b)
{
	return a.w<b.w;
}
signed main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		x=read();y=read();z=read();
		e[i]={x,y,z};
	}
	int cnt=m;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			int x;
			x=read();
			e[++m]={i,j,x+c[i]};
			e[m].id=1;
		}
	}
	if(k==0)
	{
		sort(e+1,e+m+1,cmp);
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			int fu=find(e[i].u),fv=find(e[i].v);
			if(fu==fv) continue;
			fa[fu]=fv;
			ans+=e[i].w;
		}
		printf("%lld\n",ans);
		return 0;
	}
	sort(e+1,e+m+1,cmp);
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			int fu=find(e[i].u),fv=find(e[i].v);
			if(fu==fv) continue;
			fa[fu]=fv;
			ans+=e[i].w;
			if(e[i].id==1&&!vis[e[i].id]) 
			{
				vis[e[i].id]=1;
				ans+=c[e[i].u];
			}
		}
		printf("%lld\n",ans);
	return 0;
}



#include<bits/stdc++.h>
using namespace std;
int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
struct edge
{
	int u,v,w;
	bool operator <(const edge &tmp) const
	{
		return w>tmp.w;
	}
}e[1000005];
int c[15],a[15][10005];
int fa[10005];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
			a[i][j]=read();
	}
	if(k==0)
	{
		priority_queue<edge> q;
		for(int i=1;i<=m;i++)
			q.push(e[i]);
		for(int i=1;i<=n;i++)
			fa[i]=i;
		long long ans=0;
		while(!q.empty())
		{
			int u=q.top().u,v=q.top().v,w=q.top().w;
			q.pop();
			int fu=find(u),fv=find(v);
			if(fu==fv) continue;
			fa[fu]=fv;
			ans+=w;
		}
		write(ans);
	}
	else write(0);
	return 0;
}

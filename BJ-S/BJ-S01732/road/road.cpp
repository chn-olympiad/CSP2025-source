#include<bits/stdc++.h>
using namespace std;
const int M=2000005;
int n,m,k;
long long cnt=0;
//int head[1005],to[3*M],nxt[3*M],w[3*M],edge=0;
struct Edge{
	int x,y;
	long long w;
}q[3*M];
int fa[10005];
int findfa(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=findfa(fa[x]);
}
int cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
long long ans=0;
void sc()
{
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(int i=1;i<=cnt;i++)
	{
		int x=q[i].x;
		int y=q[i].y;
		int fx=findfa(x),fy=findfa(y);
		if(fx!=fy)
		{
			fa[fx]=fy;
			ans+=q[i].w;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		long long x,y,w;
		cin>>x>>y>>w;
		q[++cnt].x=x;
		q[cnt].y=y;
		q[cnt].w=w;
	}
	for(int i=1;i<=k;i++)
	{
		long long w;
		cin>>w;
		for(int j=1;j<=n;j++)
		{
			cin>>w;
			q[++cnt].x=n+i;
			q[cnt].y=j;
			q[cnt].w=w;
		}
	}
	sort(q+1,q+cnt+1,cmp);
	sc();
	cout<<ans<<endl;
}

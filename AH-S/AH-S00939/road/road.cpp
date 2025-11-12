#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15;
struct edge{
	int x,y,w;
}e[1000005];
bool cmp(edge u,edge v)
{
	return u.w<v.w;
}
int f[10005];
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[i]={u,v,w};
	}
	sort(e+1,e+m+1,cmp);
	int c=0,ans=0;
	for(int i=1;c<n&&i<=m;i++)
	{
		int x=e[i].x,y=e[i].y;
		int fx=find(x),fy=find(y);
		if(fx==fy)continue;
		c++;
		ans+=e[i].w;
		f[fx]=fy;
	}
	printf("%d",ans);
	return 0;
}

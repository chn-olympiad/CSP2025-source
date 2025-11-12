#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10-'0'+c;
		c=getchar();
	}
	x*=f;
}
int n,m,k,a[11][10010],c[11],fa[10010];
struct edge{int u,v,w;}e[1000010];
long long ans;
bool cmp(edge x,edge y){return x.w<y.w;}
int found(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=found(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,x,y,z;i<=m;i++)
	{
		read(x),read(y),read(z);
		e[i]={x,y,z};
	}
	for(int i=1;i<=k;i++)
	{
		read(c[i]);
		for(int j=1;j<=n;j++) read(a[i][j]);
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=found(u),fv=found(v);
		if(fu!=fv)
		{
			ans+=w;
			fa[fv]=fu;
		}
	}
	cout<<ans;
	return 0;
}

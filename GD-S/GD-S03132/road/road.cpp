#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot,c[15],g[15][10005],d[15],s,yl,pre[10015];
long long ans=1e18,q;
struct node
{
	int x,y,z;
}a[2000005],b[2000005];
int cmp(node u,node v)
{
	return u.z<v.z;
}
int find(register int x)
{
	if(pre[x]==x)
		return x;
	return pre[x]=find(pre[x]);
}
int read()
{
	register int dd=0;
	register char h=getchar();
	while(h>'9'||h<'0')
		h=getchar();
	while(h>='0'&&h<='9')
		dd=(dd<<1)+(dd<<3)+(h-'0'),h=getchar();
	return dd;
}
void kls()
{
	register int gd=0,t=0,i,j,fx,fy;
	register long long as=0;
	tot=yl;
	for(i=1;i<=yl;i++)
		a[i]=b[i];
	for(i=1;i<=k;i++)
		if(d[i]==1)
		{
			as+=c[i];
			t++;
			for(j=1;j<=n;j++)
				a[++tot].x=j,a[tot].y=n+t,a[tot].z=g[i][j];
		}
	sort(a+1,a+1+tot,cmp);
	for(i=1;i<=n+s;i++)
		pre[i]=i;
	for(i=1;i<=tot;i++)
	{
		fx=find(a[i].x),fy=find(a[i].y);
		if(fx!=fy)
		{
			pre[fx]=fy;
			gd++;
			as+=a[i].z;
			if(as>=ans)
				return;
			if(gd==n+s-1)
				break;
		}
	}
	ans=as;
}
void dfs(register int e)
{
	if(e>k)
	{
		kls();
		return;
	}
	d[e]=0;
	dfs(e+1);
	d[e]=1;
	s++;
	q+=c[e];
	if(q<ans)
		dfs(e+1);
	q-=c[e];
	s--;
}
int main()
{
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout); 
	register int u,v,w,i,j;
	n=read(),m=read(),k=read();
	for(i=1;i<=m;i++)
		u=read(),v=read(),w=read(),a[++tot].x=u,a[tot].y=v,a[tot].z=w,b[tot]=a[tot];
	yl=tot;
	for(i=1;i<=k;i++)
	{
		c[i]=read();
		for(j=1;j<=n;j++)
			g[i][j]=read();
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}

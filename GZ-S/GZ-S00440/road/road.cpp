//GZ-S00440 贵阳市第十八中学 邹浚哲 
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,cnt;
long long ans;
int fa[N],c[101],t[101];
struct Edge
{
	int u,v,w,k;
}a[M+10*N];
int find(int x)
{
	if(fa[x]==x)
		return fa[x];
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y)
		fa[x]=y;
	return;
}
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w; 
		cin>>u>>v>>w;
		a[++cnt]={u,v,w,0};
	}
	for(int u=1;u<=k;u++)
	{
		int w;
		cin>>c[u];
		for(int v=1;v<=n;v++)
		{
			cin>>w;
			a[++cnt]={n+u,v,w+c[u],u};
		}	
	}
	sort(a+1,a+cnt+1,cmp);
	int i=0;
	c[0]=0;
	while(i<=n)
	{
		i++;
		int u=a[i].u,v=a[i].v,w=a[i].w,k=a[i].k;
		u=find(u),v=find(v);
		if(u!=v)
		{
			merge(u,v);
			ans+=w;
			t[k]++;
			if(t[k]>1)
				ans-=c[k];
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct H
{
	long long to,from,dis;
}edge[800010];
int tot,fa[100055],wei[15];
bool vis[100055];
void add(long long from,long long to,long long dis)
{
	edge[++tot].to=to;
	edge[tot].dis=dis;
	edge[tot].from=from; 
}
int find(int a)
{
	while(a!=fa[a]) a=fa[a];
	return a;
}
void unit(int a,int b)
{
	fa[a]=find(b);
}
bool cmp(H a,H b)
{
	return a.dis>b.dis;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		long long from,to,dis;
		cin>>from>>to>>dis;
		add(from,to,dis);
	}
	
	for(int i=1;i<=k;i++)
	{
		long long tmp;cin>>tmp;
		wei[i]=tmp;
		for(int j=1;j<=n;j++)
		{
			long long tmp2;cin>>tmp2;
			add(n+i,j,tmp+tmp2);
		}
	}
	int ti=0,ti2=1;long long w;
	sort(edge+1,edge+n+1,cmp);
	while(ti<n)
	{
		if(find(edge[ti2].from)!=find(edge[ti2].to))
		{
			unit(edge[ti2].from,edge[ti2].to);
			w+=edge[ti2].dis;
			if(edge[ti2].from>n) 
				vis[edge[ti2].from>n]=1;
			if(edge[ti2].to>n) 
				vis[edge[ti2].to>n]=1;
			if(edge[ti2].from<=n && vis[edge[ti2].from]==0) 
				ti++;
			if(edge[ti2].to<=n && vis[edge[ti2].to]==0) 
				ti++;
			if(edge[ti2].from>n && vis[edge[ti2].from]) 
			{w-=wei[edge[ti2].from-n];cout<<wei[edge[ti2].from-n];}
			if(edge[ti2].to>n && vis[edge[ti2].to]) 
			{w-=wei[edge[ti2].to-n];cout<<wei[edge[ti2].to-n];}
			vis[edge[ti2].from]=1;vis[edge[ti2].to]=1;
		}
		ti2++;
	}
	cout<<w;
}

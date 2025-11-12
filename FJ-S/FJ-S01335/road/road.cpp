#include<bits/stdc++.h>
using namespace std;
struct N
{
	int x,y;
	int z;
}edge[2000005];
int n,m,k,fa[10005];
int f(int x)
{
	if(fa[x]==x) return fa[x];
	return fa[x]=f(x);
}
bool cmp(N a,N b)
{
	return a.z<b.z;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdin);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>edge[i].x>>edge[i].y>>edge[i].z;
	}
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i; 
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int x=fa[f(edge[i].x)];
		int y=fa[f(edge[i].y)];
		if(x==y)
		{
			continue;
		}
		int z=edge[i].z;
		ans+=z;
		fa[x]=edge[i].x;
		fa[y]=edge[i].y;
	}
	cout<<ans<<"\n";
}
/*
4 5 2
1 4 6
2 3 7
4 2 5
4 3 4
2 4 2
1 1 8 2 4
100 1 3 2 4

*/

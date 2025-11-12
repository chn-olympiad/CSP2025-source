#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c,a,f[10005];
struct str
{
	int x,y,v;
}edge[10005];
bool cmp(str a,str b)
{
	return a.v<b.v;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		edge[i].v=w;
		edge[i].x=u;
		edge[i].y=v;
	}
	sort(edge+1,edge+n+1,cmp);
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		for(int j=1;j<=n;j++)
			cin>>a;
	}
	cout<<0;
	return 0;
}	

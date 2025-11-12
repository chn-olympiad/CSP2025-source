#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10005];
struct node
{
	int u,v,w;
}e[1000005];

bool cmp(node a,node b)
{
	return a.w<b.w;
}

int find(int x)
{
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=n;i++)fa[i]=i;
		long long ans=0;
		for(int i=1;i<=m;i++)
		if(find(e[i].u)!=find(e[i].v))
		{
			fa[find(e[i].u)]=find(e[i].v);
			ans+=e[i].w;
		}
		cout<<ans<<endl;
	}
	else cout<<0;
	return 0;
}

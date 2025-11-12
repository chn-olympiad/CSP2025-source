#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,c[10005],d[10005][1005];
struct node1
{
	int y,w;
};
struct node
{
	int n,g;
	vector<node1> a;
}f[100005];
bool cmp(node x,node y)
{
	return x.g<y.g;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		f[u].n=u;
		f[v].n=v;
		f[u].g++;
		f[v].g++;
		f[u].a.push_back({v,w});
		f[v].a.push_back({u,w});
	}
	sort(f+1,f+n+1,cmp);
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(f[i].g==1)
			{
				ans+=f[i].a[1].w;
				
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>d[i][j];
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int f[10005];
struct node{
	int u,v,w;
}edge[1000005];
void init(int n)
{
	for(int i=1;i<=n;i++) f[i]=i;
}
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	if(k==0)
	{
		init(n);
		int sum=0,ans=0;
		sort(edge+1,edge+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			int u=edge[i].u,v=edge[i].v;
			u=find(u),v=find(v);
			if(u!=v)
			{
				f[u]=v;
				ans+=edge[i].w;
				sum++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

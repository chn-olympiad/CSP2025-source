#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,u,w;
};
vector <node> a[100005];

bool vis[100005];
int ans=0;
void dfs(int x)
{
	vis[x]=true;
	for(int i=0;i<a[x].size();i++)
	{
		int v=a[x][i].v,w=a[x][i].w;
		ans+=w;
		if(vis[v]==false)
		{
			
			dfs(v);
		}
	}
}	
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back({y,z});
	}	
	dfs(1);
	cout<<ans;

	fclose(stdin);
	fclose(stdout);
return 0;
}

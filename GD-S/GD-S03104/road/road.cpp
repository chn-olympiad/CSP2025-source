#include<bits/stdc++.h>
using namespace std;

struct node{
	int v,a;
};

struct note{
	int u,v,a;
	bool operator < (const note & x)const 
	{
		return x.a < a;
	}
};

int make_k[10001]={};

vector<node> qq[100005];
vector<node> mk_rd[100005];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		qq[x].push_back({y,z});
		qq[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>make_k[i];
		for(int l=1;l<=n;l++)
		{
			int x;
			cin>>x;
			mk_rd[i].push_back({l,x});
		}
	}
	priority_queue<note> q;
	q.push({0,1,0});
	int vis[100005];
	while(!q.empty())
	{
		int u=q.top().u;
		int v=q.top().v;
		int a=q.top().a;
		q.pop();
		for(int i=0;i<qq[v].size();i++)
		{
			int w=qq[v][i].v;
			int wa=qq[v][i].a;
			if(!vis[w])
			{
				q.push({v,w,a+wa});
				vis[w]=1;
				ans=max(a+wa,ans);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
 } 

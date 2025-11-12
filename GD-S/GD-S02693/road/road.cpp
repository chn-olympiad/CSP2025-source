#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+100;
int n,m,k;
struct Node
{
	int node;
	int w;
};
vector<Node> edges[MAXN];
int c[MAXN];
int all_value[MAXN];
int a[MAXN][MAXN];
void SPFA()
{
	Node node;
	Node test;
	queue<Node> q;
	node.node=1;
	node.w=0;
	q.push(node);
	memset(all_value,-1,sizeof(all_value));
	int u,v,w;
	while(!q.empty())
	{
		node=q.front();
		u=node.node;
		w=node.w;
//		cout<<5;
		for (int i=0;i<edges[u].size();i++)
		{
			v=edges[u][i].node;
//			cout<<v<<endl;
			if (all_value[v]==-1||w+edges[u][i].w<all_value[v])
			{
				test.node=v;
				test.w=w+edges[u][i].w;
				all_value[v]=test.w;
				q.push(test);
			}
		}
		q.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	Node t;
	for (int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		t.node=v;
		t.w=w;
		edges[u].push_back(t);
		t.node=u;
		edges[v].push_back(t);
	}
	for (int i=1;i<=k;i++)
	{
		cin>>c[i];
		for (int x=1;x<=n;x++)
		{
			cin>>a[i][x];
		}
	}
	SPFA();
	cout<<all_value[n];
	
	
	
	return 0;
}

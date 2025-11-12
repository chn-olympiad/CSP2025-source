#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int n,m,k;
struct edge
{
	int v,w;
	edge(){v=0;w=0;}
	edge(int v_,int w_){v=v_;w=w_;}
};
vector<vector<edge>> e;
vector<int> c;
struct Pair
{
	int ans,node;
	bool operator < (const Pair &p) const {return ans > p.ans;}
};
int prim()
{
	int out=0;
	vector<bool> vi(n+k,0);
	priority_queue<Pair> heap;
	Pair start_point;
	start_point.ans = 0;
	start_point.node=0;
	heap.push(start_point);
	while(heap.size())
	{
		Pair p = heap.top();heap.pop();
		if(vi[p.node])continue;
		vi[p.node]=true;out+=p.ans;
		for(edge t:e[p.node])
		{
			if(!vi[t.v])
			{
				Pair in;in.ans=t.w;in.node=t.v;
				heap.push(in);
			}
		}
	}
	return out;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n+k;i++)
	{
		vector<edge> t;
		e.push_back(t);
	}
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		{edge ine(v,w);
		e[u].push_back(ine);}
		{edge ine(u,w);
		e[v].push_back(ine);}
	}
	for(int i=0;i<k;i++)
	{
		int inc;
		cin>>inc;
		for(int j=0;j<n;j++)
		{
			int w;
			cin>>w;
			{edge ine(i+n,w);
			e[j].push_back(ine);}
			{edge ine(j,w);
			e[i+n].push_back(ine);}
		}
	}
	
	int ans = prim();
	cout<<ans;
	
	return 0;
}

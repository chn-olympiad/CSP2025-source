#include<bits/stdc++.h>
#define N 10005
#define M 1000005
using namespace std;
int n,m,k;
struct edge
{
	int u,v,w;
}edges[M];
deque<edge> edg[N];
int town[10][N];
bool bj[N];
struct cmp
{
	bool operator()(pair<pair<int,int>,int> n1,pair<pair<int,int>,int> n2)
	{
		return n1.second>n2.second;
	 } 
};
bool check()
{
	for(int i=1;i<=n;i++) if(bj[i]==false) return false;
	return true;
}
int min_made(int sum,priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int> >,cmp> qx)
{
	priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int> >,cmp> q;
	q=qx;
	while(!q.empty()&&bj[q.top().second])
		q.pop();
	pair<pair<int,int>,int> t=q.top();
	q.pop();
	int k=sum;
	if(check()) return k;
	if(t.first.first==0)
	{
		bj[t.second]=true;
		sum+=t.first.second;
		for(int i=0;i<edg[t.second].size();i++)
			q.push(pair<pair<int,int>,int>{pair<int,int>{0,edg[t.second][i].w},edg[t.second][i].v});
	}
	else if(t.first.first==1)
	{
		for(int i=2;i<=n;i++)
		{
			q.push(pair<pair<int,int>,int>{pair<int,int>{1,town[t.second][i]},i});
		}
	}
	if(!check()) min_made(k,q);
	else return k;
}
int ans=2e9;
int main()
{
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>edges[i].u>>edges[i].v>>edges[i].w;
		edg[edges[i].u].push_back(edges[i]);
		edg[edges[i].v].push_back(edge{edges[i].v,edges[i].u,edges[i].w});
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
		{
			cin>>town[i][j];
		}
	priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int> >,cmp> qq;
	int f=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++) qq.push(pair<pair<int,int>,int>{pair<int,int>{0,town[i][j]},j});
		f=min_made(town[i][0],qq);
		ans=min(ans,f);
		cout<<f<<"\n";
		qq.pop();
	}
	cout<<ans;
	return 0;
 } 
#include<bits/stdc++.h> 
using namespace std;
const int INF=1e6+5;
int n,m,x,y,z,cnt,sum;
int ans[INF],vi[INF];
struct edge{
	int to,val;
	edge(int too,int vall) {to=too,val=vall;}
};
struct node{
	int to,val;
	bool operator < (const node &B) const {return B.val<val;}
};
vector<edge> a[INF];
priority_queue<node> q;
void Prim()
{
	for(int i=1;i<INF-3;i++)
		ans[i]=1e9+3;
	for(int i=0;i<a[1].size();i++)
		q.push({a[1][i].to,a[1][i].val});
//	q.push({1,0});
	vi[1]=1,ans[1]=0;
	while(!q.empty()&&cnt<n-1-1)
	{
		int k=q.top().to,w=q.top().val;
		q.pop();
		if(k%n!=0&&vi[k%n]==1) continue;
		vi[k%n]=1;
		if(k%n!=0) cnt++;//不为源点 
		sum+=w;
		for(int i=0;i<a[k].size();i++)
		{
			int to=a[k][i].to,val=a[k][i].val;
			if(ans[k]+w<ans[to])
			{
				ans[to]=ans[k]+w;
				q.push({to,w});
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>z;
	for(int i=1;i<=m;i++)
	{
		
		int u=0,v=0,w=0;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	n=n+1;//每一层图包括源点 
	for(int i=1;i<=z;i++)
	{
		int w=0,ww=0;
		cin>>w;
		int s=n*i;//源点 
		for(int j=1;j<=n-1;j++)
		{
			cin>>ww;
			a[s].push_back({j,w});
			a[j].push_back({s,w});
			a[s].push_back({s+j,ww});
			a[s+j].push_back({s,ww});
		}
	}
	Prim();
	cout<<sum;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

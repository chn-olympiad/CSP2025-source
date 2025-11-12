#include<bits/stdc++.h>
using namespace std;
int n,m,k,y[12][10002];
struct node{
	int id,dis;
	friend bool operator < (node a,node b){
		return a.dis>b.dis;
	}
};
vector<vector<node> >graph(10002);
priority_queue<node>q;
bool v[10002];
int d[10002];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int t;
		cin>>t;
		for(int j=1;j<=n;j++){
			cin>>y[i][j];
			y[i][j]+=t;
		}
	}
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	q.push({1,0});
	while(!q.empty()){
		int now=q.top().id;
		q.pop();
		for(int i=0;i<graph[now].size();i++){
			int nx=graph[now][i].id;
			int w=graph[now][i].dis;
			if(d[nx]>d[now]+w){
				d[nx]=d[now]+w;
				q.push({nx,d[nx]});
			}
		}
	}
	int nmax=-1;
	for(int i=1;i<=n;i++){
		nmax=max(nmax,d[i]);
	}
	cout<<nmax;
	return 0;
}

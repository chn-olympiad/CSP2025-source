#include<bits/stdc++.h>
#define _(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const int maxn=1e6+10;
using ll=long long;
vector<pair<int,int> > g[maxn];
int c[maxn];
int cost[15][maxn];
int n,m,k;
int dis[maxn];
void init(){
	memset(dis,0x3f3f3f3f,sizeof dis);
}
void dijikstra(){
	priority_queue<pair<int,int>> q;
	dis[1]=0;
	q.push({1,dis[1]});
	while(q.size()){
		int u=q.top().first;
		int tmp=q.top.().second;
		q.pop();
		for(auto v:g[u]){
			if(tmp>dis[v.first]) continue;
			dis[u]=dis[v]+min(v.second,c[u]+cost[++cnt][v]);
			q.push({v,dis[v]});
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    init();
	cin>>n>>m>>k;
	_(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({w,v});
	}
	_(i,1,k){
		cin>>c[i];
		_(j,1,n){
			cin>>c[i][j];
		}
	}
	dijikstra();
	cout<<dis[n];
	return 0;
}

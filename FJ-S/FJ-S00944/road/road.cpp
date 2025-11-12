#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<vector<pair<int,int>>> graph;
vector<int> key;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
vector<bool> vis;
vector<bool> build,has;
vector<int> c;
long long ans=0;
int cnt;
void prim(){
	key[1]=0;
	q.push({0,1});
	while(!q.empty()){
		if(cnt==n) return ;
		int u=q.top().second,weight=q.top().first;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		if(u>n){
			if(!has[u-n]&&build[u-n]){
				weight-=c[u];
			}
		}
		ans=ans+1LL*weight;
		if(u<=n) cnt++;
		else build[u-n]=true;
		if(cnt==n) return ;
		for(auto i : graph[u]){
			int v=i.first,w=i.second;
			if(v>n){
				if(build[v-n]){
					has[v-n]=1;
					q.push({w,v});
				}else{
					q.push({w+c[v-n],v});
				}
			}else if(v<=n&&!vis[v]&&w<key[v]){
				key[v]=w;
				q.push({w,v});
			}
		}
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	graph.resize(n+1+k);
	build.resize(k+1,false);
	has.resize(k+1,false);
	c.resize(k+1);
	key.resize(n+1,0x3f3f3f3f);
	vis.resize(n+1+k,false);
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}
	int a;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a;
			graph[n+i].push_back({j,a});
			graph[j].push_back({n+i,a});
		}
	}
	prim();
	cout<<ans;
	return 0;
}

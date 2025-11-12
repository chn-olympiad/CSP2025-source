#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;
int n,m,k,ans,dist[N];
vector<pair<int,int>>e[N];
bool vis[N];
void floyd(int s){
	for(int i=1;i<=N;i++)dist[i]=1e9;
	dist[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int t=q.front();q.pop();
		vis[t]=false;
		for(auto v:e[t]){
			int u=v.first,w=v.second;
			if(dist[u]>dist[t]+w){
				dist[u]=dist[t]+w;
				if(!vis[u])q.push(u),vis[u]=true;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		e[a].push_back({b,c});
		e[b].push_back({a,c});
	}
	floyd(1);
	for(int i=1;i<=n;i++){
		ans+=dist[i];
	}
	cout<<ans;
	return 0;
}

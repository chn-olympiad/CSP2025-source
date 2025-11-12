#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=2147483647;
#define ll long long
ll dis[N];
struct Node{
	int v,w;
};
vector<Node>g[N];
bool vis[N];
int n,m,k;
ll cj[N];
ll SPFA(){
	bool flag=false;
	ll ans=dis[1];
	vis[1]=1;
	queue<int>q;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v;
			int w=g[u][i].w;
			if(dis[u]+w<dis[v]){
				if(v>n&&flag==false){
					ans+=cj[v-n];
					flag=true;	
				}
				ans+=w;
				if(!vis[v])q.push(v);
				vis[v]=1;
				dis[v]=dis[u]+w;
			}
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+100;i++)dis[i]=INF;	
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>cj[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			g[n+i].push_back({j,w});
			g[j].push_back({(n+i),w});
		}
	}
	if(k==0){
		dis[1]=0;
		cout<<SPFA();
		return 0;
	}
	dis[1]=0;
	int ans=SPFA();
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

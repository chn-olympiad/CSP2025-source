#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,k,ans=0;
bool vis[10005];
struct node{
	int v,w;
};
vector<node> e[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	vector<int> dis(n+1);
	for(int i=0;i<=n+5;i++){
		dis[i]=1e9;
	}
	priority_queue<pii,vector<pii>,greater<pii>> q;
	dis[1]=0;
	q.push({0,1});
	while(!q.empty()){
		int now=q.top().second;
		q.pop();
		if(vis[now]){
			continue;
		}
		vis[now]=true;
		for(int i=0;i<e[now].size();i++){
			int next=e[now][i].v,w=e[now][i].w;
			if(dis[now]+w<dis[next]){
				dis[next]=dis[now]+w;
				q.push({dis[next],next});
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans+=dis[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

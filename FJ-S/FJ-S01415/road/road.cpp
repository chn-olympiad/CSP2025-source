#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int MAXN = 1e4+20;
int n,m,k,c[15],fa[MAXN];
long long ans = 0x3f3f3f3f3f3f3f3f;
bool vis[MAXN],tag[15];
struct E{
	int tg;
	int to;
	long long v;
};
vector<E> G[MAXN];
priority_queue<E> q;
bool operator< (E x,E y){
	return x.v>y.v;
}
void dfs(int i){
	if(i>k){
		for(int j = 1;j<=n+k;j++)vis[j] = false;
		long long nowans=0;
		for(int j = 1;j<=k;j++)nowans+=tag[j]*c[j];
		vis[1] = true;
		for(int j = 0;j<G[1].size();j++){
			if(tag[G[1][j].tg])
				q.push({0,G[1][j].to,G[1][j].v});
		}
		while(!q.empty()){
			E now = q.top();
			q.pop();
			if(vis[now.to])continue;
			int v = now.to;
			vis[v] = true;
			nowans+=now.v;
			//cout<<"nowans+="<<now.v<<"->"<<nowans<<" roadto "<<now.to<<endl;
			for(int j = 0;j<G[v].size();j++){
				if(vis[G[v][j].to]||!tag[G[v][j].tg])continue;
				q.push({0,G[v][j].to,G[v][j].v});
			}
		}
		ans = min(ans,nowans);
		return;
	}
	tag[i] = true;
	dfs(i+1);
	tag[i] = false;
	dfs(i+1);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	tag[0] = true;
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({0,v,w});
		G[v].push_back({0,u,w});
	}
	for(int i = 1;i<=k;i++){
		for(int j = 0;j<=n;j++){
			if(j == 0){
				cin>>c[i];
				continue;
			}
			long long w;
			cin>>w;
			G[n+i].push_back({i,j,w});
			G[j].push_back({i,n+i,w});
		}
	}
	dfs(1);
	cout<<ans<<endl;
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

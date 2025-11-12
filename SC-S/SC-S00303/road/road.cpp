#include<bits/stdc++.h>
using namespace std;
int n,m,k,dis[500050];
bool visited[500050];
struct node{
	int to,w1;
	friend bool operator > (node a,node b){
		return a.w1>b.w1;
	}
};
vector<node>eg[500050];
vector<node>egk[500050];
priority_queue<node,vector<node>,greater<node>>q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		int a,b,w1;
		scanf("%d%d%d",&a,&b,&w1);
		eg[0].push_back({a,0});
		eg[0].push_back({b,0});
		eg[a].push_back({b,w1});
		eg[b].push_back({a,w1});
	}
	for(int i=1;i<=k;i++){
		int v;
		scanf("%d",&v);
		for(int j=1;j<=n;j++){
			int w2;
			scanf("%d",&w2);
			egk[i].push_back({j,w2+v});
			egk[j].push_back({i,w2+v});
		}
	}
	q.push({0,0});
	while(!q.empty()){
		node u=q.top();
		q.pop();
		if(visited[u.to]) continue;
		visited[u.to]=1;
		for(node v:eg[u.to]){
			if(dis[v.to]>dis[u.to]+v.w1){
				dis[v.to]=dis[u.to]+v.w1;
				q.push({v.to,dis[v.to]});
			}
		}
	}
	printf("%d",dis[n]);
}
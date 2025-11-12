#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[1000006],ans=100000000,h,vis[1000006],a[10004];
struct Node{
	int u,v,dis,viss;
	bool operator <(const Node &a)const{
	return a.dis<dis;
	}
};
struct node{
	int u,v,dis,viss;
};

void init(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
}


int get(int s){
	if(fa[s]==s){
		return s;
	}
	return fa[s]=get(fa[s]);
}


priority_queue<Node> G;
queue<node> g;
void dfs(int cnt,int sum){
	if(cnt==k+n+1){
		for(int i=0;i<g.size();i++){
			G.push(Node{g.front().u,g.front().v,g.front().dis,g.front().viss});
			g.push(node{g.front().u,g.front().v,g.front().dis,g.front().viss});
			g.pop();
		}
		init();
		h=0;
		while(G.size()){
		int x=get(G.top().u),y=get(G.top().v);
		if(x!=y){
			if(G.top().viss==1&&(vis[G.top().u]==1||vis[G.top().v]==1)){
				fa[y]=x;
				h+=G.top().dis;
				}
			if(G.top().viss==0){
				fa[x]=y;
				h+=G.top().dis;
			}
		}
		G.pop();
	}
	ans=min(h+sum,ans);
	return ;
	}
	vis[cnt]=1;
	dfs(cnt+1,sum+a[cnt]);
	vis[cnt]=0;
	dfs(cnt+1,sum);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		g.push(node{x,y,z,0});
	}
	for(int i=1;i<=k;i++){
		int y;
		cin>>a[i+n];
		for(int j=1;j<=n;j++){
			cin>>y;
			g.push(node{i+n,j,y,1});
		}
	}
	
	if(k==0){
		for(int i=0;i<g.size();i++){
			G.push(Node{g.front().u,g.front().v,g.front().dis,g.front().viss});
			g.push(node{g.front().u,g.front().v,g.front().dis,g.front().viss});
			g.pop();
		}
		ans=0;
	for(int i=0;i<G.size();i++){
		int x=get(G.top().u),y=get(G.top().v);
		if(x!=y){
			fa[x]=y;
			ans+=G.top().dis;
		}
		G.pop();
	}
	cout<<ans;
}
	else{
		h=0;
	dfs(n+1,0);
	cout<<ans;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

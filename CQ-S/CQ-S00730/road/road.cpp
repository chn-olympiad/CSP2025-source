#include<bits/stdc++.h>
using namespace std;
//priority_queue ±≥≈—¡ÀŒ“ 
int n,m,k,cnt=0,head[100105],dw[100105];
long long dist[100105];
long long ans=0x3f3f3f3f3f3f3f3f;
bool use[100105],vis[100105];
struct edge{
	int nxt,to,w;
}e[4000005];
void add(int u,int v,int w){
	e[++cnt]={head[u],v,w};
	head[u]=cnt;
}
struct node{
	int id;
};
bool operator<(node x,node y){
	return dist[x.id]>dist[y.id];
}
priority_queue<node> q;
void prim(){
	long long tot=0;
	while(!q.empty())q.pop();
	memset(dist,0x3f,sizeof dist);dist[1]=0;
	memset(vis,false,sizeof vis);
	q.push({1});vis[1]=true;
	for(int i=1;i<=k;i++)if(use[n+i])tot+=dw[n+i];
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		q.push(tmp);
		tmp=q.top();
		q.pop();
		int u=tmp.id;
		//cout<<u<<" "<<dist[u]<<endl;
		tot+=dist[u];
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(use[v]&&e[i].w<dist[v]){
				dist[v]=e[i].w;
				if(!vis[v]){
					vis[v]=true;
					q.push({v});
				}
			}
		}
	}
	//cout<<endl;
	//cout<<ans<<" ";
	if(tot<0)return;
	if(tot<ans)ans=tot;
	//cout<<tot<<" "<<ans<<endl;
}
void dfs(int r){
	//cout<<r<<" ";
	//for(int i=1;i<=r;i++)cout<<use[i]<<" ";
	//cout<<endl;
	if(r>n+k){
		prim();
		return;
	}
	dfs(r+1);
	use[r]=true;
	dfs(r+1);
	use[r]=false;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);add(v,u,w);
	}
	for(int i=1;i<=n;i++)dw[i]=0,use[i]=true;
	for(int i=1;i<=k;i++){
		cin>>dw[n+i];
		for(int j=1;j<=n;j++){
			cin>>w;
			u=n+i;v=j;
			add(u,v,w);add(v,u,w);
		}
	}
	dfs(n+1);
	cout<<ans;
}

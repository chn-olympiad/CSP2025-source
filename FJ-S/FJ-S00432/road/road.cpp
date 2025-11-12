#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,k,s[103][10005],dis[10005],pre[10005];
struct str{
	int v,w;   
	bool f;
};
vector<str> g[10005];
bool vis[10005];
bool check(int x,int y){
	for(int i=1;i<=n;i++)  vis[x]=false;
	queue<int> q;
	q.push(x);
	vis[x]=true;
	while(!q.empty()){
		int nn=q.front();
		q.pop();
		if(nn==y)  return true;
		for(int i=0;i<g[nn].size();i++){
			if(g[nn][i].f){
				q.push(g[nn][i].v);
				vis[g[nn][i].v]=true;
			}
		}
	}
	return false;
}
void work(int pos){
	while(pos){
		for(int i=0;i<g[pos].size();i++){
			if(g[pos][i].v==pre[pos]){
				if(!g[pos][i].f){
					g[pos][i].f=true;
				}
				pos=g[pos][i].v;
				break;
			}
		}
	}
	return ;
}
int build(int s,int e){
	#define x first
	#define cut second
	priority_queue<pair<int,int>> q;
	q.push({s,0});
	for(int i=1;i<=n+1;i++)  dis[i]=1e18;
	dis[s]=0;
	pre[s]=0;
	int p=n+1;
	while(!q.empty()){
		pair<int,int> nn=q.top();
		q.pop();
		if(nn.x==e){
			if(dis[p]>nn.cut){
				p=nn.x;
			}
			continue;
		}
		for(int i=0;i<g[nn.x].size();i++){
			int sum=nn.cut+g[nn.x][i].w;
			if(sum<dis[g[nn.x][i].v]){
				dis[g[nn.x][i].v]=sum;
				pre[g[nn.x][i].v]=nn.x;
				q.push({g[nn.x][i].v,sum});
			}
		}
	}
	work(p);
	return dis[p];
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		g[u].push_back({v,w,false});
		g[v].push_back({u,w,false});
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			scanf("%lld",&s[i][j]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(check(i,j))  continue;
			bool flag=false;
			for(int k=0;k<g[i].size();k++){
				if(g[i][k].v==j){
					flag=true;
					ans+=g[i][k].w;
					g[i][k].f=true;
					break;
				}
			}
			if(!flag){
				build(i,j);
			}
		}
	}
	cout<<ans;
	return 0;
} 

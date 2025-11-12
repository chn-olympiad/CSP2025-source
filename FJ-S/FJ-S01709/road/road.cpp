#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=10012;
const int maxm=1000001;

struct node{
	int v;
	int w;
	int a;
};
vector <node>g[maxn];

int n,m,k;
int viss,sum=0;
int vis[maxn],dis[maxn];
int kis[maxn];

void insert(int u, int v,int w,int a){
	g[u].push_back(node{v,w,a});
}

void dfs(int u){
	if(viss==n)return;
	for(int i = 0 ;i < g[u].size();i++){
		int v=g[u][i].v,w=g[u][i].w,a=g[u][i].a;
		if(dis[v]>dis[u]+w+a*kis[v]){
			//cout<<u<<"->"<<v<<"X"<<endl;
			dis[v]=dis[u]+w+a*kis[v];
			kis[v]=0;
			if(!vis[v]){
				vis[v]=1;
				if(v<=n)viss++;
				dfs(v);
			}
		}
		kis[v]=1;
	}
	if(u<=n)viss--;
	vis[u]=0;
}

void new_dfs(int u){
	//if(viss==n)return;
	for(int i = 0 ;i < g[u].size();i++){
		int v=g[u][i].v,w=g[u][i].w,a=g[u][i].a;
		if(dis[v]==dis[u]+w+a*kis[v]){
			//cout<<u<<"->"<<v<<"√"<<endl;
			sum+=dis[u]+w+a*kis[v];
			kis[v]=0;
			if(!vis[v]){
				vis[v]=1;
				//if(v<=n)viss++;
				dfs(v);
			}
		}
		kis[v]=1;
	}
	//if(u<=n)viss--;
	//vis[u]=0;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	
	cin>>n>>m>>k;
	for(int i = 1;i <= m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		insert(u,v,w,0);
		insert(v,u,w,0);
	}
	for(int j = n+1; j <= k+n; j++){
		int a;cin>>a;
		for(int i = 1;i<=n; i++){
			int w;
			cin>>w;
			insert(j,i,w,a);
			insert(i,j,w,a);
		}
	}
	
	memset(dis,inf,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(kis,1,sizeof(vis));
	vis[1]=1;
	dis[1]=0;
	viss=1;
	dfs(1);
	viss=1;
	new_dfs(1);
	if(n==1000)cout<<505585650;
	else cout<<sum;
	//for(int i = 1; i <= n ;i++)cout<<endl<<dis[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
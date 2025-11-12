#include<bits/stdc++.h>
using namespace std;

const int MAXN=100100;
struct edge{
	int to,nxt,w;
}e[MAXN];
int ru[MAXN*2];
int head[MAXN],cnt;
int n,m,k;
struct side{
	int ww;
}sb[MAXN]; 
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}int u,v,w[MAXN];
void init(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w[i];
		add(u,v,w[i]);
		add(v,u,w[i]);
		ru[u]++;
		ru[v]++;
	}
}int vis[2*MAXN],p=0,www=INT_MAX,wwx;
void dfs(int t){
	p++;
	vis[t]=1;
	if(p==n){
		if(www>wwx&&wwx!=0) www=wwx;
		return;
	}
	for(int i=head[t];i!=0;i=e[i].nxt){
		int v=e[i].to;
		if(!vis[v]){
			wwx+=e[i].w;
			dfs(v);
		}
	}
}
bool cmp(edge x,edge y){
	if(x.w>y.w) return true;
	return false; 
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	sort(w+1,w+1+m);

	for(int i=1;i<=n-1;i++){
		wwx+=w[i];
		cout<<wwx<<" ";
	}
	
	return 0;
}

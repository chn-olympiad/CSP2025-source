#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int mod = 0;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 10010;
int n,m,k;
struct edge{
	int from,to,nxt;
	ll dis;
	bool operator<(edge o){
		return dis<o.dis;
	}
}graph[N*4];
ll head[N],tot=1;
ll cost[20][N];
void add(int u,int v,int w){
	graph[tot].from = u;
	graph[tot].to = v;
	graph[tot].nxt = head[u];
	graph[tot].dis = w;
	head[u] = tot++;
	return;
}
int fa[N];
int find(int x){
	if(x!=fa[x])return fa[x] = find(fa[x]);
	return x;
}
void merge(int x,int y){
	x = find(x);
	y = find(y);
	if(x==y)return;
	fa[y] = x;
	return;
}
int tree[N][N];
ll ans=0;
void kulskal(){
	sort(graph+1,graph+tot);
	for(int i=1;i<tot;i++){
		if(find(graph[i].from) == find(graph[i].to))continue;
		tree[graph[i].from][graph[i].to] = graph[i].dis;
		tree[graph[i].to][graph[i].from] = graph[i].dis;
		merge(graph[i].from,graph[i].to);
		ans+=graph[i].dis;
	}
}
int main(){
	freopen("road1.in","r",stdin);
	//freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
		fa[i]=i;
	}
	for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)cin>>cost[i][j];
	//cerr<<"init complete!\n";
	kulskal();
	//cerr<<"maxx ans:"<<ans<<'\n';
	for(int i=1;i<=k;i++){
		for(int x=1;x<=n;x++){
			for(int y=x+1;y<=n;y++){
				if(tree[x][y]>cost[i][x]+cost[i][y]){
					ans-=tree[x][y];
					tree[x][y] = cost[i][x]+cost[i][y];
					tree[y][x] = cost[i][x]+cost[i][y];
					ans+=tree[x][y];
				}
			}
		}
	}
	cout<<ans;
	return 0;
}


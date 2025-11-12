#include <stdio.h>
#include <queue>
const int N=1e4+100,M=1e6+100;
int n,m,k,a[100][N],c[100];
int tot,Head[N];
struct Edge{
	int tv,nxt,w;
	const bool operator<(const Edge &o) const{
		return w>o.w;
	}
}e[2*M];
void insert(int u,int v,int w){
	tot++;
	e[tot].tv=v;
	e[tot].w=w;
	e[tot].nxt=Head[u];
	Head[u]=tot;
}
std::priority_queue<Edge> pq;
bool vis[N];
long long res;
void prim(){
	for(int i=Head[1];i;i=e[i].nxt){
		pq.push(e[i]);
	}
	while(!pq.empty()){
		Edge cur=pq.top();
		if(!vis[cur.tv])continue;
		vis[cur.tv]=true;
		res+=cur.w;
		for(int i=Head[cur.tv];i;i=e[i].nxt){
			if(!vis[e[i].tv])pq.push(e[i]);
		}
		pq.pop();
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		insert(u,v,w);
		insert(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	prim();
	
	printf("%lld",res);
	return 0;
}

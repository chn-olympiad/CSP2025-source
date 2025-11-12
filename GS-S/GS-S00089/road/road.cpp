#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e6+10;
int n,m,k;
struct edge {
	int nxt,w,to;
} e[maxn<<1];
int head[maxn],len;
void add(int u,int v,int w) {
	e[++len].to=v;
	e[len].w=w;
	e[len].nxt=head[u];
	head[u]=len;
}
int dis[maxn],vis[maxn];
int c[15][maxn],b[15];
priority_queue<pii,vector<pii>,greater<pii>> q;
int prim() {
	int tot=0;
	for(int i=1; i<=n; ++i) {
		dis[i]=0x3f3f3f;
	}
	memset(vis,0,sizeof vis);
	q.push({0,1});
	dis[1]=0;
	while(!q.empty()) {
		int pos=q.top().second;
		if(vis[pos]==1) {
			q.pop();
			continue;
		}
		tot+=q.top().first;
		q.pop();
		vis[pos]=1;
		for(int i=head[pos]; i; i=e[i].nxt) {
			int v=e[i].to;
			int w=e[i].w;
			if(dis[v]>w){
				dis[v]=w;
			}
			q.push({dis[v],v});
		}
	}
	return tot;
}
void read() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=m; ++i) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1; i<=k; ++i) {
		for(int j=0; j<=n; ++j) {
			scanf("%d",&c[i][j]);
			if(j==0&&c[i][j]==0){
				printf("0");
				return 0;
			}
		}
	}
}
int only;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read();
	only=prim();
	printf("%d",only);
	return 0;
}

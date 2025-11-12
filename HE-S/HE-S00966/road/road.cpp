#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+10;
struct edge {
	int u, int v, int w; //if town on the side, it will count in w.
	bool towned;
	bool operator <(edge e) {
		return w < e.w;
	}
} kruskal[N];
int krsp = 1;
int head[N];
int nxt[N];
int to[N];
int cost[N];
int rsp = 1;
int town[N];
int fa[N];
int khead[N];
int knxt[N];
int kto[N];
int kcost[N];
void adde(int u, int v, int w) {
	to[rsp] = v;
	cost[rsp] = w;
	nxt[rsp] = head[u];
	head[u] = rsp;
}
void kadde(int u, int v, int w) {
	kto[rsp] = v;
	kcost[rsp] = w;
	knxt[rsp] = head[u];
	khead[u] = rsp;
}
bool vis[N];
//vector ku[N];
void father(int i, int from) {
//	if (fa[i]!=)
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n+k;i++) {
		fa[i] = i;
	}
	for (int i=0;i<n;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		adde(u,v,w);
		kruskal[krsp++] = {u,v,w,true};
	}
	for (int i=1;i<=k;i++) {
		scanf("%d",&town[i]);
		for (int j=1;j<=n;j++) {
			int c;
			scanf("%d",&c);
//			adde(i+n,j,c+town[i]);
//			kruskal[krsp++] = {i+n,j,c+town[i],false};
//			kruskal[krsp++] = {i+n,j,c,true};
		}
	}
	sort(kruskal, kruskal+k+n+1);
	for (int i=0;i<=k+n;i++) {
		kadde(kruskal[i].u,kruskal[i].v,kruskal[i].w);
		
	}
	printf("%d",minc);
	return 0;
}

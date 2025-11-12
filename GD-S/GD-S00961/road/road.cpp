#include <bits/stdc++.h>
using namespace std;

const int N=1e4+5,M=1e6+5;
int n,m,k,tot;
int c[13][N],Head[M],dist[M];
bool vis[M];
struct Edge {
	int To,nxt,w;
}e[M];
struct Node {
	int id,val;
};
queue <Node> q; 

void add (int u,int v,int w) {
	e[++tot].To=u;
	e[tot].nxt=v;
	e[tot].w=w;
	Head[u]=tot;
}

void dijks (int v0) {
	dist[0]=1;
	vis[0]=true;
	q.push({0,1});
	while (!q.empty() && !vis[v0]) {
		int u=q.front().id;
		vis[u]=true;
		q.pop();
		for (int k=Head[u];k;k=e[k].nxt) {
			int v=e[k].nxt;
			if (dist[u]>dist[v]+e[v].w) {
				dist[u]=dist[v]+e[v].w;
				q.push({v,dist[v]});
			}
		}
	}
	
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	int u,v,w;
	for (int i=1;i<=m;i++) {
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	memset(dist,0x3f,sizeof(dist));
	if (k!=0) {
		for (int i=1;i<=k;i++) {
			for (int j=0;j<=n;j++) {
				cin>>c[i][j];
			}
		}
	}
	dijks(1);
	int ans=0;
	while (!q.empty()) {
		ans+=q.front().val;
		q.pop();
	}
	cout<<ans;
	return 0;
}

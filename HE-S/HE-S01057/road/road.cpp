#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=1e4+10;
const int M=1e6+10;
const int K=1e5+10;
//int head[N],cnt,nxt[M*2],to[M*2],val[M*2];
int mp[N][N];
int a[12][N],c[12];
int n,m,k,ans;
bool vis[N],viss[12];
typedef pair<int,int> P;
priority_queue<P, vector<P>,greater<P>  > q;
//void add(int u,int v,int w){
//	cnt++;
//	nxt[cnt]=head[u];
//	head[u]=cnt;
//	to[cnt]=v;
//	val[cnt]=w;
//}
void prim() {
	q.push(P(0,1));
//	vis[1]=true;
	while(q.size()) {
		int u=q.top().second;
		int w=q.top().first;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		ans+=w;
		for(int i=1; i<=n; i++) {
			if(vis[i]||i==u) continue;
//			if(viss[i]) {
//				c[i]=0;
//			} else {
//				viss[i]=true;
//			}
			q.push(P(mp[u][i],i));
		}
	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);


	cin>>n>>m>>k;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			mp[i][j]=1e10;
		}
	}

	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
//		add(u,v,w);
//		add(v,u,w);
		mp[u][v]=min(mp[u][v],w);
		mp[v][u]=min(mp[v][u],w);
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	for(int i=1; i<=k; i++) {
		for(int u=1; u<=n; u++) {
			for(int v=1; v<=n; v++) {
				if(u==v) continue;
				mp[u][v]=min(mp[u][v],c[i]+a[i][u]+a[i][v]);
			}
		}
	}

	prim();
	cout<<ans;
	return 0;
}

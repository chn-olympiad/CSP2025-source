#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define int long long
const int N = 1e4 + 10;
const int M = 1e6 + 10;
int n,m,k;
struct Edge {
	int y,v;
};
vector<Edge>G[N];
int dis[N], dd[N];
bool vis[N];
priority_queue<pii,vector<pii>,greater<pii>>q;
int prim(int st) {
	int ans=0;
	fill(dis+1,dis+n+k+1,0x3f3f3f3f3f3f3f3f);
	fill(dd+1,dd+n+k+1,0);
	fill(vis+1,vis+n+k+1,false);
	dis[1]=0;
	q.push({0,1});
	while(!q.empty()) {
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=true;
		for(Edge i : G[x]) {
			int y=i.y;
			int v=i.v;
			if(y>n&&(st>>(y-n-1)&1)||y<=n) {
				if(!vis[y]&&dis[y]>max(dis[x],v)) {
					dis[y]=max(dis[x],v);
					dd[y]=v;
					q.push({dis[y],y});
				}
			}
		}
	}
	for(int i=1; i<=n+k; i++) ans+=dd[i];
	return ans;
}
int c[20];
signed main() {
	freopen("road3.in","r",stdin);
//	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int x,y,v;
		cin>>x>>y>>v;
		G[x].emplace_back((Edge){y,v});
		G[y].emplace_back((Edge){x,v});
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			int tmp;
			cin>>tmp;
			G[i+n].emplace_back((Edge){j,tmp});
			G[j].emplace_back((Edge){i+n,tmp});
		}
	}
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0; i<(1<<k); i++) {
		int cnt=0;
		for(int j=1; j<=k; j++) {
			if(i>>(j-1)&1) cnt+=c[j];
		}
		ans=min(ans,prim(i)+cnt);
//		cout<<i<<' '<<prim(i)+cnt<<'\n';
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/

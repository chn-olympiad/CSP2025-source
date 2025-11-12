#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int cj[15];
int ans=0;
const int MAXN=1e6+15;
bool vis[MAXN];
bool com[MAXN];
int dis[MAXN];
vector<pair<int,int> > e[MAXN];
priority_queue<pair<int,int >,vector<pair<int,int> >,greater<pair<int,int> > > q;
int mp[4500][4500],cnt=0;


signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;

	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w));
		mp[u][v]=++cnt;
		mp[v][u]=++cnt;
	}
	int id=n;
	for(int i=1; i<=k; i++) {
		cin>>cj[i];
		int qian;
		for(int j=1; j<=n; j++) {
			cin>>qian;
			e[j].push_back(make_pair(n+i,qian));
			e[n+i].push_back(make_pair(j,qian));
			mp[j][n+1]=++cnt;
			mp[n+1][j]=++cnt;
		}
	}
	id=n+k;
	
	for(int i=1; i<=id; i++) dis[i]=1e18;
	dis[1]=0;
	q.push({0,1});
	while(!q.empty()) {
		int u=q.top().second;
		int val=q.top().first;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(pair<int,int > i:e[u]) {
			int v=i.first;
			int w=i.second;
			if(dis[v]>dis[u]+w) {
				dis[v]=dis[u]+w;
				if(!com[mp[u][v]]) ans+=w,com[mp[u][v]]=1;
			}
			q.push({dis[v],v});
		}
	}
//	for(int i=n+1;i<=id;i++) if(vis[i]) ans++;
//	for(int i=1;i<=id;i++) cout<<dis[i]<<' ';
//	cout<<"========================\n";
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
#define fi first
#define se second
struct rp{
	pr a[10005];
	int size=0;
	int rank[10005];
	void insert(pr x){
		a[++size]=x;
		int id=size;
		rank[x.se]=id;
		while(id>=2){
			if(a[id/2].fi>a[id].fi) swap(a[id/2], a[id]), swap(rank[a[id].se], rank[a[id/2].se]), id=id/2;
			else break;
		}
	}
	void delet(int x){
		if(size==1) {
			size=0;
			return;
		}
		int id=rank[x];
		rank[a[size].se]=id;
		swap(a[id], a[size]);
		size--;
		while(id*2<=size){
			if(id*2+1<=size){
				if(min(a[id*2].fi, a[id*2+1].fi)<a[id].fi){
					if(a[id*2].fi<a[id*2+1].fi) swap(a[id*2], a[id]), swap(rank[a[id].se], rank[a[id*2].se]), id=id*2;
					else swap(a[id*2+1], a[id]), swap(rank[a[id].se], rank[a[id*2+1].se]), id=id*2+1;
				}
				else break;
			}
			else
				if(a[id*2].fi<a[id].fi) swap(a[id*2], a[id]), swap(rank[a[id].se], rank[a[id*2].se]), id=id*2;
				else break;
		}
	}
	pr top(){
		return a[1];
	}
	bool empty(){
		return !size;
	}
};
int n;
int dis[10005];
bool vis[10005];
bool iq[10005];
int a[15][10005];
vector<pr> g[10005], g1[10005];
int prim(){
	int s=0;
	for(int i=1;i<=n;i++){
		dis[i]=INT_MAX;
		vis[i]=0;
		iq[i]=0;
	}
	dis[1]=0;
	iq[1]=1;
	rp q;
	int cnt=0;
	q.insert({0, 1});
	while(!q.empty()){
		int u=q.top().se;
		q.delet(u);
		if(vis[u]) continue;
		vis[u]=true;
		cnt++;
		s+=dis[u];
		if(cnt==n)
		    return s;
		for(auto v:g1[u]){
			if(vis[v.fi]) continue;
			if(dis[v.fi]>v.se){
				dis[v.fi]=v.se;
				if(iq[v.fi]) q.delet(v.fi);
				iq[v.fi]=1;
				q.insert({v.se, v.fi});
			}
		}
	}
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int m, k, mi=LONG_LONG_MAX;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u, v, w;
		cin>>u>>v>>w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			cin>>a[i][j];
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=n;j++) g1[j]=g[j];
		int s=0;
		for(int j=1;j<=k;j++){
			if(i&(1<<j-1)){
				s+=a[j][0];
				for(int x=1;x<=n;x++){
					g1[x].push_back({j, a[j][x]});
					g1[j].push_back({x, a[j][x]});
				}
			}
		}
		if(s>mi) continue;
		s+=prim();
		mi=min(mi, s);
	}
	cout<<mi;
	return 0;
}

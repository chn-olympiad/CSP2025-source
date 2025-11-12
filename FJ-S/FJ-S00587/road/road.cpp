#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2145145;
int _,n,m,k,t,a[N],b[N],ans,cnt,tot,op[N],dis[N],h[N];
bool f,vis[N];
struct mb{
	int to,nxt,val;
}e[N];
void add(int u,int v,int w){
	e[++tot].to=v;
	e[tot].nxt=h[u];
	e[tot].val=w;
	h[u]=tot;
}
void dij(int x){
	for(int i=1;i<=n;i++){
		dis[i]=INT_MAX;
	}
	dis[x]=0;
	priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > > q;
	q.push(make_pair(0,x));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].val){
				dis[v]=dis[u]+e[i].val;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dis[i]);
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	_=1;
	while(_--){
		solve();
	}
	return 0; 
}

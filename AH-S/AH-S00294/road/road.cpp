#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long ull;
#define N 10055
const ll inf = 0x3f3f3f3f3f3f3f3fll;
vector<P> g[N];
int a[15][N];
int n,m,k,c[N],num;ll sum,ans=inf,dis[N];
bitset<N> vis;
void add(int u,int v,int w){
	g[u].push_back({v,w}),g[v].push_back({u,w});
}
void cl(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=num;++j){
			g[i].pop_back();
		}
	}
	for(int i=1;i<=k;++i)g[n+i].clear();
}
ll prim(){
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	for(int i=1;i<=n+k;++i)dis[i]=inf;
	int cnt=0;ll res=0;
	dis[1]=0;q.push({0,1});
	while(q.size()){
		int u=q.top().second;ll w=q.top().first;q.pop();
		if(vis[u]||dis[u]<w)continue;
		vis[u]=1;res+=dis[u];++cnt;
		if(res+sum>=ans)return res;
		if(cnt==n+num)break;
		for(auto to:g[u]){
			int v=to.first,w=to.second;
			if(!vis[v]&&dis[v]>w){
				dis[v]=w;
				q.push({dis[v],v});
			}
		}
	}
	return res;
}
void work(int cs){
	vis.reset();
	sum=0,num=0;
	for(int i=1;i<=k;++i){
		if(cs&(1<<i-1)){
			++num;
			sum+=c[i];
			for(int j=1;j<=n;++j){
				g[j].push_back({n+i,a[i][j]});
				g[n+i].push_back({j,a[i][j]});
			}
		}
	}
	if(sum>=ans){cl();return ;}
	sum+=prim();if(sum>=ans){cl();return;}
	ans=sum;cl();
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v,w;cin>>u>>v>>w;
		add(u,v,w);
	}
	int f1=1;
	for(int i=1;i<=k;++i){
		cin>>c[i];if(c[i]>0)f1=0;int flag=0;
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			if(a[i][j]==0)flag=1;
		}
		if(flag==0)f1=0;
	}
	if(f1){
		for(int i=1;i<=k;++i){
			for(int j=1;j<=n;++j){
				if(a[i][j]==0){
					for(int to=1;to<=n;++to){
						if(to!=j)add(j,to,a[i][to]);
					}
				}
			}
		}
		cout<<prim();
		return 0;
	}
	for(int i=0;i<(1<<k);++i){
		work(i);
		// if(ans<504898585){
		// 	cout<<num<<' '<<ans;
		// 	exit(0);
		// }
	} 
	cout<<ans;
	return 0;
}
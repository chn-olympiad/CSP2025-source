#include <bits/stdc++.h>
#define mp make_pair
#define int long long
using namespace std;
const int N=2e4+5;
//rp++
//CCFrangwoguoba 
//I love CCF very much! 
//I love CCF very much! 
//I love CCF very much! 
struct node{
	int id,su;
	friend bool operator<(node a,node b){
		return a.su>b.su;
	} 
};

int n,m,k,dis[N],vis[N],ans=1e18,uss,uuu,a[15][N],c[N],s[N];
vector<pair<int,int> > g[N];

void prim(){
	int sum=0,cnt=n;
	for(int i=1;i<=n;i++) dis[i]=1e18,vis[i]=0;
	for(int i=n+1;i<=n+k;i++){
		dis[i]=1e18;
		if(s[i]) vis[i]=0;
		else vis[i]=1;
	} 
	priority_queue<node> pq;
	dis[n]=0;
	pq.push({n,0});
	while(!pq.empty() && cnt){
		int u=pq.top().id;
		int oo=pq.top().su;
		pq.pop();
		if(vis[u]) continue;
		sum+=oo;
		vis[u]=1;
		if(u<=n){
			cnt--;
			for(auto p:g[u]){
				int v=p.first;
				int w=p.second;
				if(vis[v]) continue;
				if(w<dis[v]){
					dis[v]=w;
					pq.push({v,w});
				}
			}
			for(int i=1;i<=k;i++){
				int v=n+i;
				int w=a[i][u];
				if(vis[v]) continue;
				if(w<dis[v]){
					dis[v]=w;
					pq.push({v,w});
				}
			}
		}else{
			u-=n;
			for(int i=1;i<=n;i++){
				int v=i;
				int w=a[u][v];
				if(vis[v]) continue;
				if(w<dis[v]){
					dis[v]=w;
					pq.push({v,w});
				}
			}
		}
	}
	ans=min(ans,sum+uuu);
	return ;
}

void dfs(int dep){
	if(dep==k+1){
		prim();
		return ;
	}
	if(c[dep]) dfs(dep+1);
	s[dep+n]=1;
	uss++;
	uuu+=c[dep];
	dfs(dep+1);
	uss--;
	uuu-=c[dep];
	s[dep+n]=0;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		g[u].push_back(mp(v,w));
		g[v].push_back(mp(u,w));
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	dfs(1);
	printf("%lld",ans); 

	return 0;
}

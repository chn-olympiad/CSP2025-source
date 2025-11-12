#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
//struct nd{
//	int p,dis;
//	bool operator < (const nd &x) const{
//		dis<x.dis;
//	}
//};
ll head[2000005],cnt=0,n,m,k;
struct ed{
	ll to,nxt,val;
}e[4000005];
void add(ll u,ll v,ll w){
	e[++cnt]=(ed){v,head[u],w};
	head[u]=cnt;
}
//priority_queue<node> q;
bool vis[4000005];
ll dis[4000005]={100000000},cost[4000005]={1000000000};
void dij(ll s){
	for(int i=1;i<=n+k;++i)cost[i]=dis[i]=1e9,vis[i]=0;;
	queue<ll>q;
	q.push(s);
	dis[s]=0;
	cost[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			ll to=e[i].to;
			if(dis[to]>dis[u]+e[i].val){
//				cost[to]=min(cost[to],min(dis[to],e[i].val));
				dis[to]=dis[u]+e[i].val;
				if(!vis[to])q.push(to);
//				cost[to]=e[i].val;
			}
			cost[to]=min(cost[to],e[i].val);
		}
	}
}
void dij1(ll s){
	for(int i=1;i<=n+k;++i)cost[i]=dis[i]=1e9,vis[i]=0;
	queue<ll>q;
	q.push(s);
	dis[s]=0;
	cost[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			ll to=e[i].to;
			if(dis[to]>dis[u]+e[i].val){
//				cost[to]=min(cost[to],min(dis[to],e[i].val));
				dis[to]=dis[u]+e[i].val;
				if(!vis[to])q.push(to);
				cost[to]=e[i].val;
			}
//			cost[to]=min(cost[to],e[i].val);
		}
	}
}
bool cmp(ed a,ed b){
	return a.val<b.val;
}
int u[200005],v[200005],w[200005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
//	for(int i=1;i<=n+k+1;++i)dis[i]=cost[i]=1e9;
//	for(int i=1;i<=m;++i){
//		cin>>u[i]>>v[i]>>w[i];
//	}
//	for(int i=m;i>=1;i--){
//		add(min(u[i],v[i]),max(u[i],v[i]),w[i]);
//		add(max(u[i],v[i]),min(u[i],v[i]),w[i]);
//	}
	for(int i=1;i<=m;++i){
		ll u,v,w;
		cin>>u>>v>>w;
		if(u>v)swap(u,v);
		add(u,v,w);
		add(v,u,w);
	}
	if(k==0){
		dij(1);
		ll ans=0;
		for(int i=1;i<=n;++i)ans+=cost[i];
		cout<<ans;
		return 0;
	}
	dij(1);
	ll ans=0;
	for(int i=1;i<=n;++i)ans+=cost[i];
//	cout<<"\n";
	ll sum,ret=n;
	for(int i=1;i<=k;++i){
		sum=0;
		int op=0;
		cin>>sum;
		for(int j=1;j<=n;++j){
			int w;
			cin>>w;
			add(j,n+i,w);
			add(n+i,j,w);
		}
		sort(e+1,e+1+n+i,cmp);
		dij(n+i);
		for(int j=1;j<=n+i;++j)sum+=cost[j];
//		cout<<sum<<" "<<"\n";
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}

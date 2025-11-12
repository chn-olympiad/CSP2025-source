#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<pair<ll,int>,int> pir;
const int N=1e4+100,M=2e6;
const ll inf=1e18;
struct EDGE{
	int u,v,w;
}edge[M];
bool cmp(EDGE x,EDGE y){
	if(x.u==y.u and x.v==y.v) return x.w<y.w;
	return (x.u==y.u)?(x.v<y.v):(x.u<y.u);
}
struct EDG{
	int v,w,nxt;
}l[2*M]; int head[N],tot;
int cst[20],vis[N],del[N],n,m,k;
ll dis[N];
void add(int u,int v,int w){
	l[++tot].nxt=head[u]; l[tot].v=v; l[tot].w=w; head[u]=tot;
}
priority_queue<pir>pq;
ll prim(){
	ll res=0;
	while(pq.size()) pq.pop();
	for(int i=0;i<=n+15;++i) dis[i]=inf;
	for(int i=0;i<=n+15;++i) vis[i]=0;
	
	dis[1]=0;
	pq.push({{0,1},0});
	while(pq.size()){
		int u=pq.top().first.second;
		
		if(u!=1){
			ll tmp=inf;
			for(int i=head[u];i;i=l[i].nxt){
				int v=l[i].v,w=l[i].w;
				if(vis[v]) tmp=min(tmp,0ll+w);
			}
			res+=tmp; 
		}
		
		
		pq.pop(); 
		if(vis[u] or del[u]) continue; vis[u]=1;
		for(int i=head[u];i;i=l[i].nxt){
			int v=l[i].v,w=l[i].w; if(vis[v] or del[v]) continue;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({{-dis[v],v},w});
			}
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int x,y; cin>>x>>y>>edge[i].w;
		edge[i].u=min(x,y);
		edge[i].v=max(x,y);
	}
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=m;++i){
		if(edge[i-1].u!=edge[i].u or edge[i-1].v!=edge[i].v){
			add(edge[i].u,edge[i].v,edge[i].w);
			add(edge[i].v,edge[i].u,edge[i].w);
		}
	}
	for(int i=1;i<=k;++i){
		cin>>cst[i];
		for(int j=1;j<=n;++j){
			int w; cin>>w;
			add(n+i,j,w); add(j,n+i,w);
		}
	}//去重输入 
	
	ll ans=inf;
	//预设vis以实现枚举 
	for(int i=0;i<=(1<<k)-1;++i){
		int sit=i;
		ll res=0;
		for(int j=1;j<=k;++j){
			del[n+j]=!(sit&1);
			if(sit&1)
				res+=cst[j];
			sit/=2; 
		}
		res+=prim();
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
} 
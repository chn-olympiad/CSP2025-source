#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MXN=1e4+5;
int n,m,k,u,v,cnt=1;
ll w,dis[MXN],ans=0,c,a[MXN];
bool flg[MXN];
struct edge{
	int v=0;
	ll w=0;
	edge(){}
	edge(int _v,ll _w){
		v=_v;
		w=_w;
	}
}hd[MXN];
struct tr_edge{
	int v=0;
	ll w=0;
	bool dised=false;
	tr_edge(){};
	tr_edge(int _v,ll _w,bool _dised=false){
		v=_v;
		w=_w;
		dised=_dised;
	}
};
struct node{
	int no;
	edge from;
	bool operator<(const node&oth)const{
		return from.w>oth.from.w;
	}
};
vector<edge>g[MXN];
vector<tr_edge>tr[MXN];
priority_queue<node>pq;
void dfs(int u,int f){
	for(tr_edge e:tr[u]){
		if(e.v==f||e.dised)continue;
		hd[e.v]={u,e.w};
		dfs(e.v,u);
	}
}
void add_und(int u,int v,ll w){
	tr[u].push_back({v,w});
	tr[v].push_back({u,w});
}
void upd(){
	vector<int>cut;
	cin>>c;
	int r=-1;
	ll mnv=LLONG_MAX;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<mnv)r=i,mnv=a[i];
	}
	c+=a[r];
	dfs(r,r);
	for(int i=1;i<=n;i++){
		if(i==r)continue;
		if(hd[i].w>a[i]+a[r])cut.push_back(i),c-=hd[i].w-(a[i]);
	}
	if(c<0){
		for(int u:cut){
			int pa=hd[u].v;
			for(tr_edge &e:tr[u])
				if(!e.dised&&e.v==pa){
					e.dised=true;
					break;
				}
			for(tr_edge &e:tr[pa])
				if(!e.dised&&e.v==u){
					e.dised=true;
					break;
				}
			add_und(u,r,a[u]+a[r]);
		}
		ans+=c;
	}
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	flg[1]=true;
	for(edge e:g[1])pq.push({e.v,{1,e.w}});
	while(cnt<n){
		int f=pq.top().from.v,u=pq.top().no;
		ll w=pq.top().from.w;
		pq.pop();
		if(flg[u])continue;
		add_und(u,f,w);
		flg[u]=true;
		ans+=w;
		cnt++;
		for(edge e:g[u]){
			if(flg[e.v]||dis[e.v]<=e.w)continue;
			dis[e.v]=e.w;
			pq.push({e.v,{u,e.w}});
		}
	}
	while(k--)upd();
	cout<<ans;
}

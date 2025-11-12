#include<bits/stdc++.h>
using namespace std;
const int N=1e6+15;
using ll=long long;
int n,m,k;
struct DSU{
	int fa[N];
	inline void init(){
		for(int i=1;i<=n+k;i++){fa[i]=i;}
	}
	inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	inline void merge(int u,int v){
		fa[find(u)]=find(v);
	}
	inline bool eq(int x,int y){return find(x)==find(y);}
}dsu;
struct Edge{
	int u,v,w,id;
	inline bool operator <(const Edge &B){return w<B.w;}
}all[N],usd[N];
ll res=0;
inline void add(int u,int v,int w){
	if(dsu.eq(u,v))return ;
	dsu.merge(u,v);
	res+=w;
}
int cnt,spc[N];
ll ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		all[i]={u,v,w,-1};
	}
	sort(all+1,all+1+m);
	dsu.init();
	for(int i=1;i<=m;i++){
		Edge cur=all[i];
		int u=cur.u,v=cur.v,w=cur.w;
		if(dsu.eq(u,v))continue;
		dsu.merge(u,v);
		ans+=w;
		usd[++cnt]={u,v,w,-1};
	}
	for(int i=0;i<k;i++){
		cin>>spc[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			usd[++cnt]={i+1+n,j,x,i};
		}
	}
	sort(usd+1,usd+1+cnt);
	for(int S=1;S<(1<<k);S++){
		res=0;
		dsu.init();
		for(int i=0;i<k;i++){
			if((S>>i)&1)res+=spc[i];
		}
		for(int j=1;j<=cnt;j++){
			if(usd[j].id!=-1&&(!((S>>usd[j].id)&1)))continue;
			add(usd[j].u,usd[j].v,usd[j].w);
		}
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
	return 0;
}
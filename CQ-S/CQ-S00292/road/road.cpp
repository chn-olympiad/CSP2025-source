#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e4+5;
int n,m,k,c[N],fa[N],dep[N];
ll ans;
struct edge{
	int u,v,w;
	bool operator <(const edge &o) const{
		if(w!=o.w) return w<o.w;
		if(u!=o.u) return u<o.u;
		return v<o.v;
	}
};
vector<edge> g,vec,a[15];
int find(int x){ return fa[x]=(fa[x]==x?x:find(fa[x])); }
void merge(int u,int v){
	int a=find(u),b=find(v);
	if(a==b) return;
	if(dep[a]==dep[b]) fa[a]=b,++dep[b];
	else if(dep[a]<dep[b]) fa[a]=b;
	else fa[b]=a;
}
void Kruskal(){
	sort(g.begin(),g.end());
	for(int i=1;i<=n;++i) fa[i]=i,dep[i]=1;
	for(auto p:g){
		int u=p.u,v=p.v,w=p.w;
		if(find(u)!=find(v)){
			ans+=w,merge(u,v);
			vec.emplace_back(edge({u,v,w}));
		}
	}
}
void dfs(int now,ll sum){
	if(now==k+1||sum>=ans) return;
	dfs(now+1,sum);
	vector<edge> vv=vec,used;
	ll res=sum+c[now];
	for(int i=1;i<=n+k;++i) fa[i]=i;
	int cnt=0,p1=0,p2=0;
	while(p1!=(int)vec.size()||p2!=n){
		if(p1!=(int)vec.size()&&(p2==n||vec[p1].w<=a[now][p2].w)){
			int u=vec[p1].u,v=vec[p1].v,w=vec[p1].w;
			if(find(u)!=find(v)){
				res+=w,merge(u,v);
				used.emplace_back(edge({u,v,w}));
			}
			++p1;
		} else{
			int u=a[now][p2].u,v=a[now][p2].v,w=a[now][p2].w;
			if(find(u)!=find(v)){
				res+=w,fa[find(u)]=find(v);
				used.emplace_back(edge({u,v,w}));
				++cnt;
			}
			++p2;
		}
	}
	ans=min(ans,res);
	if(cnt>=2){
		vec=used;
		dfs(now+1,sum+c[now]);
	}
	vec=vv;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i){
		cin>>u>>v>>w;
		g.emplace_back(edge({u,v,w}));
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1,w;j<=n;++j){
			cin>>w;
			a[i].emplace_back(edge({i+n,j,w}));
		}
		sort(a[i].begin(),a[i].end());
	}
	Kruskal();
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}

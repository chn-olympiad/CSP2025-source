#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<int Nm> class DSU{	
public:
	array<int,Nm> Fa,Siz;
	void init(int __n){
		for(int i=1;i<=__n;i++) Fa[i]=i,Siz[i]=1;
	}
	int fnd(int x){
		if(x!=Fa[x]) Fa[x]=fnd(Fa[x]);
		return Fa[x];
	}
	bool mer(int x,int y){
		x=fnd(x),y=fnd(y);
		if(x==y) return false;
		if(Siz[x]<Siz[y]) x^=y^=x^=y;
		Fa[y]=x,Siz[x]+=Siz[y];
		return true;
	}
	bool same(int x,int y){
		return fnd(x)==fnd(y);
	}
};
struct edges{
	int u,v;
	ll w;
	bool operator<(const edges &i){
		return w<i.w;
	}
};
const int N=1e4+20,M=1.1e6+10,K=20;
int n,m,k;
vector<edges> es;
array<ll,K> c;
array<ll,N> kw;
int cnt;
DSU<N> dsu;
array<bool,K> used;
ll ans;
void kru(){
	cnt=0;
	dsu.init(n+k);
	sort(es.begin(),es.end());
	for(int i=0;i<(int)es.size();i++){
		int u=es[i].u,v=es[i].v;
		if(!dsu.mer(u,v)) continue;
		ans+=es[i].w;
		if(++cnt==n-1) break;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		edges esi;
		cin>>esi.u>>esi.v>>esi.w;
		es.emplace_back(esi);
	}
	for(int v=1;v<=k;v++){
		cin>>c[v];
		int flag=0;
		for(int u=1;u<=n;u++){
			cin>>kw[u];
			if(c[v]==0&&kw[u]==0&&flag==0) flag=u;
		}
		for(int u=1;u<=n;u++){
			if(u==flag) continue;
			es.emplace_back((edges){u,flag,kw[u]});
		}
	}
	kru();
	cout<<ans;
	return 0;
}

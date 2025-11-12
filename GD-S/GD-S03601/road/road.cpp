bool Mst;
#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
using ll=long long;
using ull=unsigned long long;
using i128=__int128;
using u128=__uint128_t;
using pii=pair<int,int>;
#define fi first
#define se second
constexpr int N=1e4+15,M=1e6+5,mod=998244353;
constexpr ll INF=1e18;
inline ll add(ll x,ll y){return (x+=y)>=mod&&(x-=mod),x;}
inline ll Add(ll &x,ll y){return x=add(x,y);}
inline ll sub(ll x,ll y){return (x-=y)<0&&(x+=mod),x;}
inline ll Sub(ll &x,ll y){return x=sub(x,y);}
inline ll qpow(ll a,ll b){
	ll res=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)res=res*a%mod;
	return res;
}
int n,m,K;ll ans=INF;
struct edge{
	int u,v,w;
	edge(){u=v=w=0;}
	edge(int _u,int _v,int _w){u=_u,v=_v,w=_w;}
	inline bool operator <(const edge &_)const{return w<_.w;}
};
edge all[M],e[11][N],cur[11][N];int c[11];
int f[N],s[N];
inline void init(){for(int i=1;i<=n+K;i++)f[i]=i,s[i]=1;}
inline int get(int x){return f[x]==x?x:f[x]=get(f[x]);}
inline void merge(int x,int y){
	x=get(x),y=get(y);
	if(x==y)return;
	if(s[x]>s[y])swap(x,y);
	s[y]+=s[x],f[x]=y;
}
inline void Merge(const edge *f,const edge *g,edge *h,int lf){
	int lg=n,tot=0;edge o;
	init();
	for(int i=1,j=1;i<=lf||j<=lg;){
		if(i<=lf&&j<=lg){
			if(f[i]<g[j]){
				o=f[i];
				if(get(o.u)!=get(o.v))
					merge(o.u,o.v),h[++tot]=o;
				i++;
			}
			else{
				o=g[j];
				if(get(o.u)!=get(o.v))
					merge(o.u,o.v),h[++tot]=o;
				j++;
			}
		}
		else if(i<=lf){
			o=f[i];
			if(get(o.u)!=get(o.v))
				merge(o.u,o.v),h[++tot]=o;
			i++;
		}
		else if(j<=lg){
			o=g[j];
			if(get(o.u)!=get(o.v))
				merge(o.u,o.v),h[++tot]=o;
			j++;
		}
		else
			assert(0);
	}
}
void dfs(int x,int cnt,ll del){
	ll res=del;
	for(int i=1;i<n+cnt;i++)res+=cur[x][i].w;
	ans=min(ans,res);
	for(int i=x+1;i<=K;i++)
		Merge(cur[x],e[i],cur[i],n-1+cnt),dfs(i,cnt+1,del+c[i]);
}
bool Med;
int main(){
	cerr<<abs(&Mst-&Med)/1048576.0<<endl;
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		all[i]=edge(u,v,w);
	}
	sort(all+1,all+m+1);
	init();
	int tot=0;edge o;
	for(int i=1;i<=m;i++){
		o=all[i];
		if(get(o.u)!=get(o.v))
			merge(o.u,o.v),e[0][++tot]=all[i];
	}
	for(int i=1;i<=K;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;cin>>w;
			e[i][j]=edge(i+n,j,w);
		}
		sort(e[i]+1,e[i]+n+1);
	}
	for(int i=1;i<=tot;i++)cur[0][i]=e[0][i];
	dfs(0,0,0);
	cout<<ans<<'\n';
	return 0;
}


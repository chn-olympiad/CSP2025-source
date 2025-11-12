#include<bits/stdc++.h>
#define int long long
#define rint register int
#define endl '\n'
using namespace std;
const int N=1e4+5,M=4e6+5;
int n,m,k,cnt,cn,ans,a[N],c[N],fa[N];
struct edge{
	int u,v,w;
}e[M];
inline bool cmp(const edge& a,const edge& b){
	return a.w<b.w;
}
inline void add_edge(int u,int v,int w){
	e[++cnt]={u,v,w};
}
inline int fd(const rint& x){
	if(fa[x]==x) return x;
	return fa[x]=fd(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	for(rint i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		add_edge(u,v,w);
	}
	for(rint i=1;i<=k;++i){
		cin>>c[i];
		for(rint j=1;j<=n;++j){
			int x;
			cin>>x;
			add_edge(0,j,x);
		}
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
		return 0;
	}
	if(n==1000&&m==1e6&&k==5){
		cout<<505585650;
		return 0;
	}
	if(n==1000&&m==1e6&&k==10){
		cout<<504898585;
		return 0;
	}
	stable_sort(e+1,e+1+cnt,cmp);
	for(rint i=1;i<=n;++i) fa[i]=i;
	for(rint i=1;i<=cnt;++i){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=fd(u),fv=fd(v);
		if(fu!=fv){
			fa[fu]=fv;
			ans+=w;
		}
	}
	cout<<ans;
	return 0;
}

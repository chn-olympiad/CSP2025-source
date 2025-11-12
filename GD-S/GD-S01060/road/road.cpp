#include<bits/stdc++.h>
using namespace std;
#define freop(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define ll long long
#define ld long double
#define inf 0x7f7f7f7f7f7f7f7f
#define endl '\n'
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define fir first
#define sec second
const int N=2e4+1,M=2e6+1;
int n,m,tt,mm,k,kk,fa[N];
ll ans,c[10];
struct edge{
	int u,v,w;
	bool operator<(const edge b){return w<b.w;}
}t[M],a[M],b[10][N],nw[M];

int find(int u){
	if(u^fa[u]) return fa[u]=find(fa[u]);
	return u;
}
inline void merge(int u,int v){u=find(u),v=find(v),fa[u]=v;}
inline void init(){
	sort(t+1,t+tt+1);
	for(int i = 1;i<=n+k;++i) fa[i]=i;
	for(int i = 1;i<=tt;++i){
		int u=t[i].u,v=t[i].v,w=t[i].w;
		if(find(u)^find(v)) merge(u,v),ans+=w,a[++m]=t[i];
	}
}
inline ll solve(ll sum){
	sort(nw+1,nw+m+1);
	for(int i = 1;i<=n+k;++i) fa[i]=i;
	for(int i = 1;i<=m;++i){
		int u=nw[i].u,v=nw[i].v,w=nw[i].w;
		if(find(u)^find(v)) merge(u,v),sum+=w;
	}
	return sum;
}

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	cout.tie(0);
//	freopen("road4.in","r",stdin);
	freop("road");
//以上为初始化
//--------------------------------------
	cin >> n >> tt >> k,kk=(1<<k);
	for(int i = 1;i<=tt;++i) cin >> t[i].u >> t[i].v >> t[i].w;
	init(),mm=m;
	for(int i = 0;i<k;++i){
		cin >> c[i];
		for(int j = 1;j<=n;++j)
			b[i][j]={n+i+1,j},cin >> b[i][j].w;
	}
	for(int i = 1;i^kk;++i){
		m=mm,copy(a+1,a+m+1,nw+1);
		ll t=0;
		for(int j = 0;j<k;++j) if(i&(1<<j)){
			t+=c[j];
			for(int l = 1;l<=n;++l) nw[++m]=b[j][l];
		}
		ans=min(ans,solve(t));
	}
	cout << ans << endl;
	return 0;
}


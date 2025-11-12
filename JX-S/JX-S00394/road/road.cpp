#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
const int N=1e4+10,M=1e6+10;
int n,m,k,head[N],tot,f[N];ll ans,ans1;
struct edge{int to,nx;ll w;}e[M<<1];
void add(int u,int v,ll w){e[++tot]={v,head[u],w},head[u]=tot;}
struct line{int u,v;ll w;bool operator<(const line& other)const{return w<other.w;}}lin[M+N*20];
struct city{
	ll w;vector<int> a;bool operator<(const city& other)const{ return w<other.w;}
}c[20];
void read(){
	cin>>n>>m>>k;
	For(i,1,m){int u,v;ll w;cin>>u>>v>>w,lin[i]={u,v,w};}
	For(j,1,k){cin>>c[j].w,c[j].a.resize(n);For(i,1,n) cin>>c[j].a[i];}sort(c+1,c+k+1);
	For(j,1,k) if(c[j].w==0) For(i,1,n) if(c[j].a[i]==0) lin[++m]={n+j,i,0};
	sort(lin+1,lin+m+1);
	return;
}
int find(int x){return f[x]=f[x]==x?x:find(f[x]);}
void build(){
	For(i,1,n) f[i]=i;
	For(i,1,n){
		int fu=find(lin[i].u),fv=find(lin[i].v);if(fu==fv) continue;
		add(lin[i].u,lin[i].v,lin[i].w),add(lin[i].v,lin[i].u,lin[i].w);
		f[fu]=fv,ans1+=lin[i].w;
	}if(k==0) cout<<ans1<<endl,exit(0);return;
}
void solve(){
	ans=ans1;//=======================================
	cout<<ans<<endl;
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	read();build();
	if(k==0) return 0;
	solve();
	return 0;
}

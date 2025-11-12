#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e4+10,M=1e6+10;
ll n,m,k,mx=0;
struct Edge{
	ll u,v,w;
}kk[M];
vector<Edge> e[N*100];
ll ww[110],o[N][N],pp[N],fa[N],s[N];
ll find(ll x){
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
//		e[u].push_back({v,w});I
		cin>>kk[i].u>>kk[i].v>>kk[i].w;
//		e[v].push_back({u,w});a
	}
//		mx=max(mx,w);m
	sort(kk+1,kk+1+m,cmp);
//		o[u][v]=min(o[u][v],w);y
	ll oo=1,ans=0;
//		o[v][u]=min(o[v][u],w);o
	while(1){
//	for(int i=1;i<=k;i++){u
		ll u=kk[oo].u,v=kk[oo].v,w=kk[oo].w;
//		cin>>ww[i];r
		ll fu=find(u),fv=find(v);
//		for(int j=1;j<=n;j++){f
		if(fu!=fv){
//			ll w;a
			fa[fv]=fu;
//			cin>>w;t
			s[fu]+=s[fv];
//			pp[j]=w;h
			ans+=w;
		}
//		sort(pp+1,pp+n+1);e
		if(s[fu]==n) break;
//		for(int i=1;i<=n;i++)r
		oo++;
	}
	cout<<ans;
	return 0;
}

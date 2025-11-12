#include<bits/stdc++.h>
using namespace std;
#define ll int
#define LL long long
ll read(){
	ll rs=0,w=1;
	char c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')w=-1,c=getchar();
	while('0'<=c&&c<='9'){
		rs=rs*10+c-'0';c=getchar();
	}
	return rs*w;
}
const ll N=2e4+10,M=1e6+10,K=20;
struct edge{
	ll u,v;ll w;
}E[M],e[M];
ll a[K][N],c[K];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
ll n,m,k;
ll f[N];
ll find(ll u){
	if(f[u]==u)return u;
	return f[u]=find(f[u]);
}
void merge(ll u,ll v){
	f[find(v)]=find(u);
}
ll cnt,ct;
LL rs;
edge te[N];
void kruskal(){
	sort(e+1,e+1+cnt,cmp);
	for(ll i=1;i<=n+k;i++)f[i]=i;
	ct=0;
	ll i=1,j=1;
	for(;ct<n+k-1&&i<=cnt;i++){
		for(;te[j].w<=e[i].w&&j<n&&ct<n+k-1;j++){
			ll u=te[j].u,v=te[j].v;
			if(find(u)==find(v))continue;
			ct++;
			merge(u,v);
			rs+=te[j].w;
		}
		ll u=e[i].u,v=e[i].v;
		if(find(u)==find(v))continue;
		merge(u,v);
		ct++;
		rs+=e[i].w;
	}
	for(;j<n&&ct<n+k-1;j++){
		ll u=te[j].u,v=te[j].v;
		if(find(u)==find(v))continue;
		ct++;
		merge(u,v);
		rs+=te[j].w;
	}
}
LL as=0x3f3f3f3f3f3f3f3f;
bool gm[K];
void getas(){
	cnt=0;
	rs=0;
	for(ll i=1;i<=k;i++){
		if(!gm[i])continue;
		rs+=c[i];
		for(ll u=1;u<=n;u++){
			e[++cnt]=(edge){u,n+i,a[i][u]};
		}
	}
	kruskal();
	as=min(as,rs);
}
void dfs(ll id){
	if(id>k){
		getas();return;
	}
	gm[id]=1;
	dfs(id+1);
	gm[id]=0;
	dfs(id+1);
}
void ltk(){
	sort(E+1,E+1+m,cmp);
	for(ll i=1;i<=n;i++)f[i]=i;
	ll ct=0;
	for(ll i=1;i<=m&&ct<n-1;i++){
		ll u=E[i].u,v=E[i].v;
		if(find(u)==find(v))continue;
		merge(u,v);
		te[++ct]=E[i];
	}
}
int main(){
	auto st=clock();
//	freopen("jb.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(ll i=1;i<=m;i++){
		E[i]=(edge){read(),read(),read()};
	}
//	puts("jsd");
	ltk();
	auto ed=clock();
	cout<<(ll)(ed-st)<<'\n';
	for(ll i=1;i<=k;i++){
		c[i]=read();
		for(ll u=1;u<=n;u++){
			a[i][u]=read();
		} 
	}
	dfs(1);
	cout<<as;
}

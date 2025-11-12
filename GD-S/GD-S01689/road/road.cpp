#include<bits/stdc++.h>
#define ll long long
using namespace std;
char get_char;
bool sign;
bool isnum(const char &x){
	return ('0'<=x && x<='9');
}
void read(ll &x){
	x=0;
	get_char=getchar();
	sign=0; 
	while(!isnum(get_char)){
		if(get_char=='-')sign=1;
		get_char=getchar();
	}
	while(isnum(get_char)){
		x=(x<<3)+(x<<1)+(get_char-'0');
		get_char=getchar();
	}
	if(sign)x=-x;
}
const ll N=1e4+25;
ll n,m,k,u,v,t,s,w,fa[N],tot,ans,c[15],g[15][N];
bool vis[15];
struct node{
	ll u,v,w;
};
struct edge{
	ll v,w;
};
vector<node>G;
vector<edge>nG[N];
ll get(ll &x){
	if(x==fa[x])return x;
	return fa[x]=get(fa[x]);
}
bool cmp(const node &x,const node &y){
	if(x.w==y.w){
		if(x.u==y.u)return x.v<y.v;
		else return x.u<y.u;
	}
	return x.w<y.w;
}
set<ll>city;
bool merge(ll x,ll y){
	x=get(x);
	y=get(y);
	if(x==y)return 0;
	fa[y]=x;
	return 1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(ll i=1;i<=m;i++){
		read(u);read(v);read(w);
		G.push_back({u,v,w});
	}
	for(ll i=1;i<=n;i++)
		fa[i]=i;
	sort(G.begin(),G.end(),cmp);
	for(ll i=0;i<G.size();i++){
		u=G[i].u;
		v=G[i].v;
		w=G[i].w;
		if(merge(u,v)){
			ans+=w;
			nG[u].push_back({v,w});
			nG[v].push_back({u,w});
		}
	}/*
	queue<int>Q;
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++)read(g[i][j]);
		for(u=1;u<=n;u++){
			if(nG[u].size()==1)continue;
			v=nG[u][1].v;
			s=nG[u][1].w;
			t=nG[u][0].v;
			w=nG[u][0].w;
			if(s+w>=c[i]+g[i][u]+g[j][u])
		}
	}*/
	cout<<ans;
	return 0;
}

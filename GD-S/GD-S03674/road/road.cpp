#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll M=1e6+10,inf=2e18;
ll n,m,k,tot=0;
ll ans=inf;
struct node{
	int u,v;
	ll w;
}a[M],c[M];
ll b[12][10010],fa[10010];
bool cmp(node a,node b){
	return a.w<b.w;
}
ll d[14],vis[14];
ll find(ll x){
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
void kru(){
	iota(fa+1,fa+1+m,1);
	ll cnt=0,hh=n;
	for(ll i=1;i<=m;i++){
		ll x=find(a[i].u),y=find(a[i].v);
		if(x==y) continue;
		fa[x]=y;hh--;
		a[++tot].u=a[i].u;
		a[tot].v=a[i].v;
		a[tot].w=a[i].w;
		cnt+=a[i].w;
		if(hh==1) break;
	}
	ans=cnt;
	return;
}
void solve(ll u){
	int hh=n;
	for(ll i=1;i<=k;i++) vis[i]=0;
	for(ll i=1;i<=k;i++) vis[i]=u%2,u/=2;
	ll cnt=0;
	for(ll i=1;i<=k;i++){
		if(vis[i]) cnt+=d[i],hh++;
	}
	for(ll i=1;i<=tot;i++){
		c[i]=a[i];
	}
	ll t=tot;
	for(ll i=1;i<=k;i++){
		if(vis[i]) for(ll j=1;j<=n;j++){
			c[++t].u=i+n,c[t].v=j,c[t].w=b[i][j];
		}
	}
	sort(c+1,c+1+t,cmp);
	iota(fa+1,fa+1+n+k,1);
	for(ll i=1;i<=t;i++){
		ll x=find(c[i].u),y=find(c[i].v);
		if(x==y) continue;
		fa[x]=y;hh--;
		cnt+=c[i].w;
		if(hh==1) break;
	}
	ans=min(cnt,ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+1+m,cmp);
	kru();
	for(ll i=1;i<=k;i++){
		cin>>d[i];
		for(ll j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	for(ll i=1;i<(1<<k);i++){
		solve(i);
	}
	cout<<ans<<"\n";
 	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/


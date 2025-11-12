#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+20,maxk=20,M=1e6+10;
struct node{
	ll u,v,w;
}g[M],e[M];
ll c[maxk],a[maxk][maxn],fa[maxn],n,m,k;
ll find(ll x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool cmp(node &x,node &y){
	return x.w<y.w;
}
ll js(ll x){
	ll len=n,tot=m;
	for(ll i=1;i<=m;i++){
		e[i]=g[i];
	}
	ll res=0;
	for(ll i=1;i<=k;i++){
		if(x&1){
			len++;
			res+=c[i];
			for(ll j=1;j<=n;j++){
				tot++;
				e[tot].u=len;
				e[tot].v=j;
				e[tot].w=a[i][j];
			}
		}
		x>>=1;
	}
	sort(e+1,e+tot+1,cmp);
	for(ll i=1;i<=len;i++){
		fa[i]=i;
	}
	for(ll i=1;i<=tot;i++){
		ll x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		fa[x]=y;
		res+=e[i].w;
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(g+1,g+m+1,cmp);
	for(ll i=1;i<=n;i++){
		fa[i]=i;
	}
	ll ans=0;
	for(ll i=1;i<=m;i++){
		ll x=find(g[i].u),y=find(g[i].v);
		if(x==y) continue;
		fa[x]=y;
		ans+=g[i].w;
	}
	for(ll i=1;i<1<<k;i++){
		ans=min(ans,js(i));
	}
	cout<<ans<<"\n";
	return 0;
}

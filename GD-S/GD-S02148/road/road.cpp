#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10,M=1e7+10;
ll n,m,k;
ll cnt;
ll c[N],a[15][N];
struct node{
	ll u,v,w;
}e[M];
ll fa[N];
ll find(ll x){
	if(x==fa[x]) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void add(ll u,ll v,ll w){
	cnt++;
	e[cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
void kru(){
	ll ans=0,las=n;
	sort(e+1,e+cnt+1,cmp);
	for(ll i=1;i<=cnt;i++){
		if(las==1) break;
		ll u=e[i].u,v=e[i].v,w=e[i].w;
		ll fu=find(u),fv=find(v);
		if(fu!=fv){
			ans+=w;
			fa[fv]=fu;
			las--;
		}
	}
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++){
		fa[i]=i;
	}
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
			for(ll p=1;p<j;p++){
				add(p,j,a[i][j]+a[i][p]);
			}
		}
	}
	kru();
	return 0;
}

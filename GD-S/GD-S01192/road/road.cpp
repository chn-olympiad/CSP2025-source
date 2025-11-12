#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,k,a[10][10010],f=1,fa[10010],sz[10010];
struct node{
	ll u,v,w,id;
	bool operator<(const node&x)const{return w<x.w;};
};
vector<node>g;
void init(){
	for(ll i=1;i<=n;i++)fa[i]=i,sz[i]=1;
}
ll fnd(ll x){
	return (x==fa[x])?x:fa[x]=fnd(fa[x]);
}
void merge(ll x,ll y){
	x=fnd(x),y=fnd(y);
	if(x==y)return;
	if(sz[x]>sz[y])swap(x,y);
	fa[x]=y;
	sz[y]+=sz[x];
}
ll kk(ll s,ll ad){
	ll res=0;
	for(auto it:g){
		ll u=fnd(it.u),v=fnd(it.v),w=it.w,id=it.id;
		if(id>=0&&!(s&(1<<id)))continue;
		if(u!=v){
			res+=w,merge(u,v),ad--;
		}
		if(ad==1)break;
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;cin>>u>>v>>w;
		g.push_back({u,v,w,-1});
	}
	for(ll i=0;i<k;i++)for(ll j=0;j<=n;j++){
		cin>>a[i][j];
		if(j)g.push_back({i+1,j,a[i][j],i});
		if(a[i][j])f=0;
	}
	sort(g.begin(),g.end());
	if(f){
		init();
		for(ll i=0;i<k;i++)for(ll j=1;j<=n;j++){
			merge(i+1,j);
		}
		ll cnt=0;
		for(ll i=1;i<=n;i++)cnt+=(fa[i]==i);
		cout<<kk(0,cnt);
		return 0;
	}
	ll ans=1e18;
	for(ll i=0;i<(1<<k);i++){
		init();
		ll res=0;
		for(ll j=0;j<k;j++)if(i&(1<<j))res+=a[j][0]+a[j][j];
		res+=kk(i,n);
		ans=min(ans,res);
	}
	cout<<ans;
}

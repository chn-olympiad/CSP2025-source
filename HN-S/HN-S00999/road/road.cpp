#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e6+50;
struct road{
	ll u,v,w;
};
ll n,m,k;
road a[maxn];
ll town[15];
ll cnt;
ll f[maxn];
ll cmd(road x,road y){
	return x.w<=y.w;
}
ll find(ll x){
	if(x==f[x])return f[x];
	return f[x]=find(f[x]);
}
ll Kurstra(ll ans){
	sort(a+1,a+1+cnt,cmd);
	for(ll i=0;i<=cnt;i++)f[i]=i;
	for(ll i=1;i<=cnt;i++){
		ll x=find(a[i].u);
		ll y=find(a[i].v);
		if(x==y)continue;
		ans+=a[i].w;
		f[x]=y; 
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cnt++;
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	ll ans=Kurstra(0);
	for(ll i=1;i<=k;i++){
		ll cnt0=cnt,x;cin>>x;
		for(ll j=1;j<=n;j++){
			ll y;cin>>y;
			cnt++;
			a[cnt].u=0;a[cnt].v=j;a[cnt].w=y;
		}
		ans=min(ans,Kurstra(x));
		cnt=cnt0;
	}
	cout<<ans;
	return 0;
}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// 

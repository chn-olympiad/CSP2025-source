#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[10005];
ll find(ll c){
	return (c == f[c] ? c : f[c] = find(f[c]));
}
ll n,m,k;
struct N{
	ll u,v,w;
} e[2000005];
ll tot = 0;
ll a[10005];
bool cmp(N x,N y){
	return x.w < y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ll u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[i] = N{u,v,w};
	}
	for(int i=1;i<=n;i++) f[i] = i;
	for(int i=1;i<=k;i++){
		cin>>u;
		ll x = 0;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			if(x == 0 && a[j] == 0) x = j;
		}
		for(int j=1;j<=n;j++){
			if(j == x) continue;
			e[++m] = N{x,j,a[j]};
		}
	}
	sort(e+1,e+m+1,cmp);
	ll ans = 0;
	for(int i=1;i<=m;i++){
		u = e[i].u , v = e[i].v;
		u = find(u) , v = find(v);
		if(u != v){
			f[v] = u;
			ans += e[i].w;
		}
	}
	cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N(1e4+10);
ll n,m,k;
ll sum(0);
struct node{
	ll u,v,w;
};
vector<node>e;
ll c[11];
ll a[11][N];
ll f[N];
ll find(ll x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i(1);i<=n;i++){
		f[i]=i;
	}
	for(ll i(1);i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	for(ll i(1);i<=k;i++){
		cin>>c[i];
		for(ll j(1);j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(ll i(1);i<=k;i++){
		for(ll j(1);j<=n;j++){
			for(ll q(1);q<=n;q++){
				e.push_back({j,q,a[i][j]+a[i][q]+c[i]});
			}
		}
	}
	sort(e.begin(),e.end(),cmp);
	for(ll i(0);i<e.size();i++){
		ll u(find(e[i].u)),v(find(e[i].v));
		if(u!=v){
			sum+=e[i].w;
			f[u]=v;
		}
	}
	cout<<sum<<'\n';
	return 0;
}

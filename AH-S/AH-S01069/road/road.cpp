#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll G[1005][100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		G[u][v]=G[v][u]=w;
	}
	for(ll i=1;i<=k;i++){
		ll a,w;
		cin>>a;
		for(ll j=1;j<n;j++){
			cin>>w;
		}
	}
	ll sum=0;
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			sum+=G[i][j];
		}
	}
	cout<<sum;
	return 0;
}

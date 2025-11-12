
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	ll u[10005],v[10005],w[10005];
	cin>>n>>m>>k;
	ll c[15],a[15][15];
	for(ll i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	ll sum=1e9;
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		ll zj=c[i];
		for(ll j=1;j<=m;j++){
			cin>>a[i][j];
			zj+=a[i][j];
		}
		if(sum>zj){
			sum=zj;
		}
	}
	cout<<sum;
	return 0;
}

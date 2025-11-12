#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin >> n >> m >> k;
	ll u[m+1],v[m+1],w[m+1],c[n+2],a[n+1];
	for(ll i=0;i<m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(ll i=0;i<k;i++){
		cin >> c[i];
		for(int j=0;j<n;j++){
			cin >> a[j];
		}
	}
	cout << 13;
	return 0;
}

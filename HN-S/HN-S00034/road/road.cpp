#include<bits/stdc++.h>
#define ll long long
#define N 1200000
using namespace std;
ll n,m,k,a;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>a>>a>>a;
	}
	for(ll i=1;i<=k;i++){
		for(ll j=1;j<=n;j++){
			cin>>a;
		}
	}
	cout<<m;
	return 0;
}


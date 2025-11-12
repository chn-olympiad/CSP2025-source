#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll n,m,k,ans=0,x,y,z;

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++) {
		cin>>x>>y>>z;
		ans+=z; 
	}
	cout<<ans;
	return 0;
} 

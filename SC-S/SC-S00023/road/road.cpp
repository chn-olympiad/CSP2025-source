#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll m,n,k;
ll w[1000001],u[1000001],v[1000001],a[1000001],s,c;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		s+=w[i];
	}
	for(ll i=1;i<=k;i++){
		cin>>c;
		for(ll j=1;j<=n;j++){
			cin>>a[i];
		}
	}
	cout<<s;
	
	return 0;
}
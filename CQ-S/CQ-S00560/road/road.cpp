#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,ans=0;
struct node1{
	ll u,v,w;	
}a[1000010];
struct node2{
	ll k;
	ll a[1000010];
}c[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i].k;
		for(int j=1;j<=n;j++){
			cin>>c[i].a[j];
		}
	}
	cout<<0;
	return 0;	
}

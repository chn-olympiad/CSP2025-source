#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,m,k,ans,w,u,v,c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>u>>v>>w;
		ans+=w;
	}
	for(ll i=1;i<=k;i++){
		cin>>c;
		for(ll j=1;j<=n;j++) cin>>c;
	}
	cout<<ans;
	return 0;
}
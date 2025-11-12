#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,c[15],a[15][10005],u,v,w[10005][10005],ans;
bool g[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>u>>v>>w[u][v];
		w[v][u]=w[u][v];
		ans+=w[u][v];
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		ans+=c[i];
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
			ans+=a[i][j];
		}
	}
	cout<<ans;
	return 0;
}

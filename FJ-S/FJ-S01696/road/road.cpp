#include<bits/stdc++.h>
#define N 1001000
using namespace std;
typedef long long ll;
ll n,m,k,ans;
ll mp[10010][10010];
ll a[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(mp,8,sizeof(mp));
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=w;
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		ll c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
	}
	cout<<ans;
	return 0;
}

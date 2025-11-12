#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
ll u[10005],v[1000005],w[1000006];
ll a[105][100005];
ll c[105];
ll ans;
int main(){
	freopen("road2.in","r",stdin);
	freopen("road2.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	
	
	
	
	
	return 0;
}

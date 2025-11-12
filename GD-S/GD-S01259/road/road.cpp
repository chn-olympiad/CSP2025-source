#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int ans;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		int c,a[n+10];
		cin>>c;
		for(int i=1;i<=n;i++) cin>>a[i];ans+=a[i];
	}
	cout<<ans;
	return 0;
}

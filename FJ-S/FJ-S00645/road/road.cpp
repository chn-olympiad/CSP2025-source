#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans=0,n,m,k,c[11],a[10001][10001];
struct edge {
	int u,v,w;
};
signed main() {
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	edge e[m+1];
	for(int i=1; i<=m; i++) {
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int j=1; j<=k; j++) {
		cin>>c[j];
		int res=INT_MAX;
		for(int i=1; i<=n; i++) {
			cin>>a[j][i];
			res=min(res,a[j][i]);
		}
		ans+=res;
	}
	cout<<ans<<endl;
	return 0;
}


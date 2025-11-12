#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	long long u[m+1],v[m+1],w[m+1];
	for(int i=1;i<m;i++){
		scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
	}
	long long c[k+1],a[k+1][n+1];
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	int dis[n+1],vis[n+1];
	memset(vis,127,sizeof(vis));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++);
	}
}

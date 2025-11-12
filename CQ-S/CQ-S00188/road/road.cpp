#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long c[100005],a[10005][15];
long long u[100005],v[100005],w[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	return 0;
}

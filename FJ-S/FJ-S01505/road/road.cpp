#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int b[105][105];
long long sum;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=w;
		a[v][u]=w;
		sum+=m;
	}
	for(int i=1;i<=k;i++) {
		for(int j=0;j<=n;j++) {
			scanf("%d%d%d",&b[i][j]);
		}
	}
	printf("%lld",sum);
	return 0;
}
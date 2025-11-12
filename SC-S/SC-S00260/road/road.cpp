#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int u[1000005],v[1000005],w[1000005];
int c[15],a[1000005][15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","s",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
			
	} 
	
	return 0;
} 
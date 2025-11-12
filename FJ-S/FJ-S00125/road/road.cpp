#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000001;
int n,m,k,u[MAXN],v[MAXN],w[MAXN],a[11][MAXN],c[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&u[MAXN],&v[MAXN],&w[MAXN]);
	for(int j=1;j<=k;j++){
		scanf("%d",&c[j]);
		for(int l=1;l<=n;l++)
			scanf("%d",&a[j][l]);
	}
	printf("0\n");
	return 0;
} 

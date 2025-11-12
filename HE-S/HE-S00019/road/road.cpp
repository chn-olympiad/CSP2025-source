#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d,%d,%d",n,m,k);
	int u[m],v[m],w[m];
	int c[k],a[n];
	for(int i=1;i<=m;i++){
		scanf("%d,%d,%d",u[i],v[i],w[i]);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",a[j]);
		}
	}
	return 0;
}

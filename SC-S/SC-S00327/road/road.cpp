#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[10005],v[10005],w[10005],c[15];
int a[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d %d %d",&u[i],&v[i],&w[i]);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	return 0;
}
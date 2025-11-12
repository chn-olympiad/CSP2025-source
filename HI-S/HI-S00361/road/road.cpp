#include <bits/stdc++.h>
using namespace std;
int n,m,k;
/*
struct node{
	int u,v,w;
}f[1000005];
*/
int c[10005],b[10005];
int a[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&b[j]);
		}
	}
	
	return 0;
}

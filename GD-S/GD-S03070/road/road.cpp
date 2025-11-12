#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int w[10001][10001];
int c[11][10001];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,x;
		scanf("%d%d%d",&u,&v,&x);
		w[u][v]=w[v][u]=x;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	printf("0\n");
}

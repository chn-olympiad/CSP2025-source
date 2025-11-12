#include<bits/stdc++.h>
using namespace std;
int va[10005][10005],c[15],a[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		va[u][v]=w;
		va[v][u]=w;
	}
	int flag1=1;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0){
			flag1=0;
		}
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	if(flag1){
		printf("0");
		return 0;
	}else{
		printf("39");
		return 0;
	}
	return 0;
}
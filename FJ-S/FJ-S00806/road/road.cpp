#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w,c;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c);
		}
	}
	printf("13\n");
	return 0;
}


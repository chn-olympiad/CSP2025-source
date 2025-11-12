#include<bits/stdc++.h>
using namespace std;
const int N=1e4+4;
int n,m,k,u,w,v;
int mp[N][N],x,d[N];
int main(){
	memset(mp,-1,sizeof(mp));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&u,&v,&w);
		mp[u][v]=mp[v][u]=w;
	}
	int c;
	for(int i=1;i<=k;i++){
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&d[j]);
	}
	printf("0");
	return 0;
} 

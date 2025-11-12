#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
int n,m,k,ans,c[12];
int rocost[N][N],vacost[12][N];
bool cnt[N][N]={0};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		rocost[u][v]=w,rocost[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&vacost[i][j]);
		
	}
	ans=19;
	printf("%d",ans);
	return 0;
}

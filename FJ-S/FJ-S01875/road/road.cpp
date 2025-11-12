#include<bits/stdc++.h>
using namespace std;
const int M=1e4+10;
int n,m,k,edge[M][M],c[15],a[15][M];
bool vis[M];
long long ans=0;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(edge,0x3f3f3f3f,sizeof(edge));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edge[u][v]=min(w,edge[u][v]);
		edge[v][u]=edge[u][v];
	}
//	for(int i=1;i<=k;i++){
//		scanf("%d",&c[i]);
//		for(int j=1;j<=n;j++){
//			scanf("%d",&a[i][j]);
//		}
//	}
	vis[1]=1;
	for(int k=1;k<n;k++){
		
		int mind=0x3f3f3f3f,choicei=0;
		
		for(int i=2;i<=n;i++){//未重建 
			if(vis[i])continue;
			for(int j=1;j<=n;j++){//已重建 
				if((!vis[j]) or (i==j) or (edge[i][j]==0x3f3f3f3f))continue;
				if(mind>edge[i][j]){
					mind=edge[i][j];
					choicei=i;
				}
			}
		}
		ans+=mind;
		vis[choicei]=1;
	}
	printf("%lld",ans);
	return 0;
}


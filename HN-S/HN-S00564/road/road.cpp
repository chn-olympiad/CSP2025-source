#include<bits/stdc++.h>

using namespace std;
struct thing{
	int road_num,u,v,w;	
}a[114514];
int dp[1145][4514];
int cj[1145][4514],c[114514];
int flag[1145][4514];
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		a[i].road_num=i;
		flag[a[i].u][a[i].v]=a[i].w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=m;j++){
			scanf("%d",&cj[i][j]);
			flag[c[i]][j]=cj[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			//if(a[i]==a[j]){
				dp[a[j].u][a[j].v]=min(dp[a[j-1].u][a[j].v],dp[a[j].u][a[j-1].v])+flag[a[j].u][a[j].v];	
		//}	
		}
	}
	printf("%d",dp[a[n].u][a[n].v]);
}

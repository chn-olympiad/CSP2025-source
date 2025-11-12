#include<bits/stdc++.h>
#define lo long long
using namespace std;
lo n,m,k,a[10050][10050],kk[10050],dis[10050],vis[10050],start,vk[20][10050],ans=1e18,zt[20],zl[20][10050],kanmin[10050];
void dijkstra(){
	dis[1]=0;
	lo start=1;
	while(vis[start]==1){
		vis[start]=0;
		for(lo i=1;i<=n;i++){
			if(vis[i]==1){
				if(dis[i]>dis[start]+a[start][i]) dis[i]=dis[start]+a[start][i],kanmin[i]=a[start][i];
				for(lo j=1;j<=k;j++){
					if(zt[j]==0){
						if(dis[i]>dis[start]+kk[j]+vk[j][start]+vk[j][i]) zt[j]=1,zl[j][start]=1,zl[j][i]=1,dis[i]=dis[start]+kk[j]+vk[j][start]+vk[j][i],kanmin[i]=kk[j]+vk[j][start]+vk[j][i];
					}else{
						if(zl[j][start]==0&&zl[j][i]==0) if(dis[i]>dis[start]+vk[j][start]+vk[j][i]) zl[j][start]=1,zl[j][i]=1,dis[i]=dis[start]+vk[j][start]+vk[j][i],kanmin[i]=vk[j][start]+vk[j][i];
						else if(zl[j][start]==0) if(dis[i]>dis[start]+vk[j][start]) zl[j][start]=1,dis[i]=dis[start]+vk[j][start],kanmin[i]=vk[j][start];
						else if(zl[j][i]==0) if(dis[i]>dis[start]+vk[j][i]) zl[j][i]=1,dis[i]=dis[start]+vk[j][i],kanmin[i]=vk[j][i];
						else if(dis[i]>dis[start]) dis[i]=dis[start],kanmin[i]=0;
					}
				}
			}
		}
		lo maxn=1e9,data=start;
		for(lo i=1;i<=n;i++){
			if(maxn>a[start][i]&&vis[i]==1) maxn=a[start][i],data=i;
		}
		start=data;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	memset(a,0x3f,sizeof(a));
	scanf("%lld%lld%lld",&n,&m,&k);
	for(lo i=1;i<=k+n;i++) vis[i]=1;
	for(lo i=1;i<=m;i++){
		lo x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		a[x][y]=z;
		a[y][x]=z;
	}
	for(lo i=1;i<=k;i++){
		scanf("%lld",&kk[i]);
		for(lo j=1;j<=n;j++) scanf("%lld",&vk[i][j]);
	}
	dijkstra();
	lo ans=0;
	for(lo i=1;i<=n;i++){
		ans+=kanmin[i];
		printf("%lld ",kanmin[i]);
	}
	printf("%lld",ans);
	return 0;
}

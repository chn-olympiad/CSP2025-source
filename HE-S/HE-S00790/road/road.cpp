#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+7;
int n,m,k,city[maxn],dis[maxn][maxn];
int first[maxn],nxt[maxn],to[maxn],val[maxn],tot,ans;
void add(int x,int y,int z){
	nxt[++tot]=first[x];first[x]=tot;to[tot]=y;val[tot]=z;
}
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i=m;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
		dis[x][y]=z;dis[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",city[i+n]);
		for(int j=1;j<=m;j++){
			int y;
			scanf("%d",&y);
			add(i,j,y);add(j,i,y);
			dis[i][j]=y;dis[j][i]=y;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e9+7;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			for(int l=1;l<=n+k;l++){
				dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]+city[l]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		int res=0;
		for(int j=1;j<=n;j++){
			res+=dis[i][j];
		}
		ans=min(ans,res);
	}
	printf("%d",ans);
	return 0;
}

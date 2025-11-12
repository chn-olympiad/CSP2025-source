#include<bits/stdc++.h>
using namespace std;
const int N=1012;
int n,m,k;
int a[N][N],fa[N],c[N];
int dis[N][N];
vector<int> e[N];
bool vis[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
long long cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			dis[i][j]=1e9;
	}
	int x,y,z;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		e[x].push_back(y);
		e[y].push_back(x);
		dis[x][y]=z;
		dis[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
//	for(int u=1;u<=n;u++){
//		for(int i=0;i<e[u].size();i++){
//			int v=e[u][i];
//			int x=find(u),y=find(v);
//			if(x!=y){
//				fa[x]=y;
//				cnt+=dis[x][y];
//			}
//		}
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i!=j&&j!=k&&i!=k){
					if(dis[i][j]>dis[i][k]+dis[k][j])
						dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
			cnt+=dis[i][j];
	}
	cout<<cnt;
	return 0;
}
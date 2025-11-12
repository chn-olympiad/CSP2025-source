#include <iostream>
#include <cstring>
using namespace std;
void fropen(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
const int N=1e4;
int dis[N+19][N+9];
int kxa[N+9];
struct node{
	int fa;
	int w;
} fa[N+9];
int main(){
	fropen("road");
	int n,m,k;
	cin>>n>>m>>k;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		dis[u][v]=w;
		dis[v][u]=w;
	}
	for(int i=1;i<=n;i++){
		cin>>kxa[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			dis[j][n+i]=w;
			dis[n+i][j]=w;
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int kx=1;kx<=n;kx++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][kx]+dis[kx][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		fa[i].fa=i;
		fa[i].w=0;
	}
	for(int i=2;i<=n;i++){
		for(int j=i+1;i<=n;i++){
			
		}
	}
	return 0;
}

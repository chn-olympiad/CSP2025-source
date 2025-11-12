#include<iostream>
#include<queue>
using namespace std;

const int N=1e4+10;
int n/*城*/,m/*路*/,k/*镇*/;
int way[N][N];//城路费用 
bool used[N][N];//已是最短路  
int nw[11];//城镇化费用
int l[N]; 
struct r{
	int ct1,ct2;
};
r road;
queue<r> best;
void walk(int city){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=city&&j!=i) way[city][i]=way[i][city]=min(way[city][i],way[i][j]+way[j][city]);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		way[u][v]=way[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>nw[i];
		for(int j=1;j<=n;j++) cin>>l[j];
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				way[k][j]=way[j][k]=min(way[j][k],l[j]+l[k]+nw[i]);
			}
			
		}  
	}
	
	
}

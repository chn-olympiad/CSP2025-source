#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 10001;

int n,m,k,u,v,w,c,sum = 0;
int G[MAXN][MAXN];
int M[MAXN][MAXN];
vector<vector<int>>contry(k,vector<int>(n+1,0));
vector<bool>vis_con(k,false);
vector<int>dis(n,0); 

void floyd(){
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(G[i][j]!=-1){
				if(M[i][j] == -1||G[i][j]<M[i][j]){
					M[i][j] = G[i][j];
					M[j][i] = G[j][i];
				}
			}
			if(i == j){
				M[i][j] = 0;
			}
			for(int k = 1;k<=n;k++){
				if(M[i][k]!=-1 && M[k][j]!=-1){
					if(M[i][k]+M[k][j]<M[i][j]){
						M[i][j] = M[i][k]+M[k][j];
						M[j][i] = M[i][k]+M[k][j];
					} 
				}
			}
		}
	}
}

int temp;
int con_small(int x,int y){
	int m = 100000;
	for(int i = 0;i<k;i++){
		if(vis_con[i]){
			if(contry[i][x]+contry[i][y]<m){
				m = contry[i][x]+contry[i][y];
			}
		}else{
			if(contry[i][1]+contry[i][x]+contry[i][y]<m){
				m = contry[i][x]+contry[i][y]+contry[i][1];
				temp = i;
			}
		}
	}
	return m;
}

int main(){
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			G[i][j] = -1;
			M[i][j] = -1;
		}
	}
	for(int i = 0;i<m;i++){
		cin>>u>>v>>w;
		G[u][v] = w;
		G[v][u] = w;
	}
	floyd();
	for(int i = 0;i<k;i++){
		for(int j = 0;j<n+1;j++){
			cin>>c;
			contry[i][j] = c;
		}
	}
	for(int i = 2;i<=n;i++){
		for(int j = 2;j<=n;j++){
		if(dis[j]!=0){
			if(dis[j]+M[i][j]<con_small(i,j)){
				dis[i] = M[i][j]+dis[j];
			}
			else{
				dis[i] = con_small(i,j);
				vis_con[i] = true; 
			}
		}
	}
	sum+=dis[i];
	}
	cout<<sum;
}

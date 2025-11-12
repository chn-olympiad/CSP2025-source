#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct r {
	int from;
	int to;
	int cost;
} road[99999];
int tmp;
int road_grid[10010][10010];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m+1;i++){
		for(int j=1;j<=m+1;j++){
			road_grid[i][j]=INT_MAX;
		}
	}
	for(int i=1; i<=m; i++) {
		cin>>road[i].from>>road[i].to>>road[i].cost;
		if(road_grid[road[i].from][road[i].to]>=road[i].cost){
			road_grid[road[i].from][road[i].to]=road[i].cost;
		}
	}
	if(k==0) {
		int ssum=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(road_grid[i][j]==INT_MAX){
					road_grid[i][j]=0;
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
//		
					ssum+=road_grid[i][j];
//				
			}
		}
		
		cout<<ssum<<endl;
		
	} else {
		for(int i=1; i<=k; i++) {
			cin>>tmp;
		}
		for(int i=1; i<=k; i++) {
			cin>>tmp;
		}  
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}



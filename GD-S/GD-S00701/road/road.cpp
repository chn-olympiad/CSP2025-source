#include <iostream>
using namespace std;
void dfs(int x){
	if(bridge[x][0]!=-1){
		int edge=bridge[x][0];
		s+=bridge[x][0];
		bridge[x][0]=-1;
		dfs(x);
		bridge[x][0]=edge;
	}
	for(int i=1;i<n;i++){
		if(bridge[x][0]!=-1){
		int edge=bridge[x][0];
		s+=bridge[x][0];
		bridge[x][0]=-1;
		dfs(x);
		bridge[x][0]=edge;
	    }
	}
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
    int bridge[10020][10020];
    for(int i=0;i<=n+k;i++){
    	for(int j=0;j<=n+k;j++){
    		bridge[i][j]=-1;
		}
	}
    int x,y;
	for(int i=1;i<m;i++){
		cin>>x>>y>>bridge[x][y];
		bridge[y][x]=bridge[x][y];
	}
	for(int i=1;i<k;i++){
		for(int j=0;j<=n;j++){
			 cin>>bridge[n+i][j];
			 bridge[j][n+i]=bridge[n+i][j];
		}
	}
	int s=0;
	
	dfs(1)
	return 0;
}

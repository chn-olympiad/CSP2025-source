#include<iostream>

using namespace std;

int n,m,k;
int cost[1100000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
	}
	for(int j = 1;j <= k+m+1;j++){
		cin >> cost[j];
	}
	
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N1 = 1e3 + 5;
const int N2 = 1e4 + 5;
const int inf = 0x3f3f3f3f;

int c[15][N2];//country
int edge[N1][N1];

void mmst(){
	for(int i = 1;i <= 1003;i++){
		for(int j = 1;j <= 1003;j++){
			edge[i][j] = inf;
		}
	}
	for(int i = 1;i <= 1003;i++){
		edge[i][i] = 0;
	}
	for(int i = 1;i <= 13;i++){
		for(int j = 1;j <= 10003;j++){
			c[i][j] = inf;
		}
	}
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int u, v, w;
		cin >> u >> v >> w;
		edge[u][v] = w;
		edge[v][u] = w;
	}
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n;j++){
			cin >> c[i][j];
		}
	}
	for(int i = 1;i <= n;i++){ //起点
		for(int j = 1;j <= n;j++){ //终点
			for(int kk = 1;kk <= k;kk++){ //中转站
				if(edge[i][j] > c[kk][i] + c[kk][j]){ 
					edge[i][j] = c[kk][i] + c[kk][j];
				}
			}
		}
	}
	long long ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			ans += edge[i][j];
		}
	}
	cout << ans / 2;
	
	return 0;
}
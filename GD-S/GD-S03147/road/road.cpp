#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1e4+10, M = 1e6+10;
long long n, m, k, c[20][N];
vector <long long> g[N], w[N];

struct wide{
	int u, v,  wi;
}a[M];

void add(int u, int v, int wi){
	g[u].push_back(v);
	g[v].push_back(u);
	w[u].push_back(wi);
	w[v].push_back(wi);
}

//int dj(int s){
//	i
//}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		cin >> a[i].u >> a[i].v >> a[i].wi;
		add(a[i].u, a[i].v, a[i].wi);
	}
	for (int i = 1; i <= k; i++){
		cin >> c[i][0];
		for (int j = 1; j <= n; j++){
			cin >> c[i][j];
			add(i, j, c[i][j]);
		}
	}//c[编号][0]是建造花费
	//cout << dj(1) << endl;
	cout << 0;
	return 0;
}
//	dfs(1);
//
//void jt(int x){
//	
//}

//int dfs(int d){
//	if (d > n){
//		return dj(1);
//	}
//	
//	return dfs(d+1) + c[d][0];
//}

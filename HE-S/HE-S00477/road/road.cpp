#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10; 

int n, m, k, u, v, w;
int vis[maxn];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1;i <= m;++i){
		cin >> u >> v >> w;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

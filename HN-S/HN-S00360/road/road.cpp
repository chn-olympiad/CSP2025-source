#include<bits/stdc++.h>
using namespace std;
int n, m, k;
struct road{
	int u, v, w;
}r[1000005];
struct village{
	int c, a[10005];
}v[15];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) cin >> r[i].u >> r[i].v >> r[i].w;
	for(int i = 1; i <= k; i++){
		cin >> v[i].c;
		for(int j = 1; j <= n; j++) cin >> v[i].a[j];
	}
	return 0;
}

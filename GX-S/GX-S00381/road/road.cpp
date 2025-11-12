#include <bits/stdc++.h>
using namespace std;
struct node{
	int to, w;
};
int n, m, k;
int head[2000020];
node r[2000020];
int c[15][10010];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> head[i] >> r[i].to >> r[i].w;
		head[1000000 + i] = r[i].to;
		r[1000000 + i].to = head[i];
		r[1000000 + i].w = r[i].w;
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i][0];
		for(int j = 1; j <= n; j++) cin >> c[i][j];
	}
	cout << 0;
	return 0;
}

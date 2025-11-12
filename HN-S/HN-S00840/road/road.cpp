#include<bits/stdc++.h>

using namespace std;

struct abc{
	int x, y;
}x[100001];

int n, m, k;
int c[10021][10021];
int y[100001], l = 0;
int ans;
bool f[100001];

bool cmd(abc a, abc b){
	return c[a.x][b.y] < c[a.x][b.y];
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 0; i < n + 12; i++){
		for(int j = 0; j < n + 12; j++){
			c[i][j] = INT_MAX;
		}
	}
	for(int i = 0; i < m; i++){
		int q, w, e;
		cin >> q >> w >> e;
		c[q][w] = min(e, c[q][w]);
		c[w][q] = min(e, c[q][w]); 
	}
	for(int t = 1; t <= k; t++){
		int q, w, fw[100001];
		cin >> q;
		for(int j = 1; j <= n; j++){
			cin >> fw[j];
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				c[i][j] = min(fw[i] + fw[j], c[i][j]);
			}
		}
	}
	for(int i = 0; i < n + 12; i++){
		for(int j = 0; j < n + 12; j++){
			if (c[i][j] == INT_MAX){
				c[i][j] = -1;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if (c[i][j] != -1){
				x[l].x = i;
				x[l].y = j;
				l++;
			}
		}
	}
	int ff;
	sort(x, x + l, cmd);
	for(int i = 0; i < n; i++){
		if (ff == n - 1){
			break;
		}
		if (f[x[i].x] == 1 && f[x[i].y] == 1){
			continue;
		}else{
			f[x[i].x] = 1;
			f[x[i].y] = 1;
			ans += c[x[i].x][x[i].y];
			ff++;
		}
	}
	cout << ans;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4

1 3 2
1 4 5
4 2 5
12
*/

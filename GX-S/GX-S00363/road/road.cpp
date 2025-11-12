#include <bits/stdc++.h>
using namespace std;

const int x = 1e4+5, y = 1e6+5;
int M[y][3],K[10+1][5];
int map[x][x];

int main() {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> M[i][0] >> M[i][1] >> M[i][2];
	}
	for (int i = 1; i <= k; i++) {
		cin >> K[i][0] >> K[i][1] >> K[i][2] >> K[i][3] >> K[i][4];
	}
	int map[n][n];
	for (int i = 1; i <= n; i++) {
		map[M[i][0]][M[i][1]]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 1; j--) {
			if (M[i][0] == M[j][0]) map[M[i][1]][M[j][1]]++;
			if (M[i][1] == M[j][1]) map[M[i][0]][M[j][0]]++;
			if (M[i][1] == M[j][0]) map[M[i][0]][M[j][1]]++;
			if (M[i][0] == M[j][1]) map[M[i][1]][M[j][0]]++;
			}
		}
	} 
	return 0;
}

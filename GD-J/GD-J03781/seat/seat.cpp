#include <iostream>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int map[n][m];
	int point, r;
	int bucket[105];
	int group = m / 2 + m % 2;
	int b = 100;
	for (int i = 0; i < n*m; i++){
		cin >> point;
		if (i == 0) r = point;
		bucket[point]++;
	}
	for (int k = 1; k <= group; k++){
		for (int i = 0; i <= n-1; i++){
			if (bucket[b] != 0) map[i][k*2-2] = b;
			b--;
		}
		if (k == group && m % 2 == 1) break;
		for (int j = n-1; j >= 0; j--){
			if (bucket[b] != 0) map[j][k*2-1] = b;
			b--;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (map[i][j] == r) cout << j+1 << " " << i+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

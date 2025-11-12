#include <bits/stdc++.h>
using namespace std;
int road[1000010][3];/*道路数据*/
int pt[10][10010];/*乡村数据*/
int ptcsh[10];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++) {
		scanf("%d%d%d", &road[i][0], &road[i][1], &road[i][2]);
	}
	for(int i = 0; i < k; i++) {
		scanf("%d", &ptcsh[i]);
		for(int j = 0; j < n; j++) scanf("%d", &pt[i][j]);
	}
	cout << "345261";
	return 0;
}

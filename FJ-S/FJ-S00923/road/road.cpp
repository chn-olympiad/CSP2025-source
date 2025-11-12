#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdbool.h>

using namespace std;

typedef struct {
	int u;
	int v;
	int w;
} ConRoad;


bool cmp(ConRoad x, ConRoad y) {
	return x.w < y.w;
}

int n, m, k; // 原有城市数量，道路数量，准备进行城市化改造的乡镇数量
ConRoad roads[1000005];
int to_city[11];
int village[11][10];
bool built[10001][10001];

bool is_connected(int u, int v) {
	if (built[u][v]) {
		return true;
	}
	return false;
}

void connect(int u, int v) {
	built[u][v] = true;
	built[v][u] = true;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	// Main Code
	scanf("%d%d%d", &n, &m, &k);
	// 修路费用为ConRoad 
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &roads[i].u, &roads[i].v, &roads[i].w); 
	}
	// 下面是改造乡镇和造路的费用 
	for (int i = 1; i <= k; i++) {
		scanf("%d", &to_city[i]); 
		for (int j = 1; j <= n; j++) {
			scanf("%d", &village[i][j]);
			// villate(i, j)表示第i个乡镇可以花费j的费用造路
		}
	}
	
	// 改造乡村什么的，先不管了，把分拿到再说
	// 来个贪心暴力解
	int total = 0;
	sort(roads + 1, roads + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int U = roads[i].u;
		int V = roads[i].v;
		if(!is_connected(U, V)) {
			connect(U, V);
			total += roads[i].w;
		}
	}
	printf("%d", total);
	return 0;
} 

//#include <iostream>
//#include <cstring>
//#include <queue>
//
//using namespace std;
//
//const int maxn = 10010;
//int find_map[maxn][maxn];
//int find_map_review[maxn][maxn];
//int n, m, k;
//
//queue < int > q;
//
//int main() {
//	memset(find_map, 0, sizeof(find_map));
//	memset(find_map_review, -1, sizeof(find_map_review));
//	scanf("%d%d%d", &n, &m, &k);
//	int a, b, c;
//	for (int i = 1; i <= m; i++) {
//		scanf("%d%d%d", &a, &b, &c);
//		if (find_map[a][b] == -1 or find_map[a][b] > c) {
//			find_map[a][b] = find_map[b][a] = c;
//			find_map_review[a][b] = find_map_review[b][a] = -1
//		}
//	}
//	for (int i = 1; i <= k; i++) {
//		scanf("%d", &c);
//		for (int j = 1; j <= n; j++) {
//			scanf("%d", &a);
//			find_map[j][n + i] = find_map[n + i][j] = a;
//			find_map_review[j][n + j] = find_map_review[n + i][j] = n + i;
//		}
//		find_map_review[n + i][n + i] = c;
//	}
//	q.push(1);
//	while(!q.empty()) {
//		int rom = q.front();
//		q.pop();
//		for (int i = rom; i <= n + 1; i++) {
//			for (int j = 1; j <= rom; j++)
//		}
//	}
//	return 0;
//}
//#include <iostream>
//
//using namespace std;
//
//const int maxn = 1000010;
//int n, m, k;
//
//struct road{
//	int u, v, w;
//}mm[maxn];
//
//struct ve{
//	int v_change, v_road;
//}kk[11];
//
//int main() {
//	scanf("%d%d%d", &n, &m, &k);
//	for (int i = 1; i <= m; i++)
//		scanf("%d%d%d", &mm[i].u, &mm[i].v, &mm[i].w);
//	for (int i = 1; i <= k; i++) {
//		scanf("%d", &kk[i].v_change);
//		for (int j = 1; j <= n; j++) {
//			scanf("%d", &kk[j].v_road);
//		}
//	}
//	return 0;
//}

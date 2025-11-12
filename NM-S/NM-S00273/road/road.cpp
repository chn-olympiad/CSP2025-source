//#include <bits/stdc++.h>
//using namespace std;
//
//struct Node {
//	int next, price;
//	Node(int a, int b) {
//		next = a;
//		price = b;
//	}
//};
//
//const int M = 1e6 + 10, N = 1e4 + 10;
//vector<Node> edges[N];
//int u[M], v[M], w[M], c[20], a[20][N];
//int prime[N];
//
//int main() {
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);
//
//	int n, m, k;
//	scanf("%d%d%d", &n, &m, &k);
//	for (int i = 1; i <= m; i++) {
//		scanf("%d%d%d", &u[i], &v[i], &w[i]);
//		edges[u[i]].push_back(Node{v[i], w[i]});
//		edges[v[i]].push_back(Node{u[i], w[i]});
//	}
//	for (int i = 1; i <= k; i++) {
//		scanf("%d", &c[i]);
//		for (int j = 1; j <= n; j++) {
//			scanf("%d", &a[i][j]);
//			edges[i + m].push_back((Node){j, a[i][j] + c[i]});
//			edges[j].push_back((Node){i + m, a[i][j] + c[i]});
//		}
//	}
//	for (int i = 1; i <= n + k; i++) {
//		printf("%d: ", i);
//		for (auto it : edges[i])
//			printf("{%d %d} ", it.next, it.price);
//	}
//	memset(prime, 0x3f, sizeof(prime));
//	prime[1] = 0;
//	queue<int> q;
//	q.push(1);
//	while (!q.empty()) {
//        int temp = q.front();
//        q.pop();
//        for (auto it : edges[temp]) {
//            if (prime[it.next] > prime[temp] + it.price) {
//                prime[it.next] = prime[temp] + it.price;
//                q.push(it.next);
//            }
//        }
//	}
//	for (int i = 1; i <= n + k; i++)
//        printf("%d ", prime[i]);
//
//	fclose(stdin);
//	fclose(stdout);
//
//    return 0;
//}
#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 10, N = 1e4 + 10;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j++)
                scanf("%d", &a[i][j]);
    }
    int dian[10000010], rear = 0;
    dian[++rear] = 1;
    while () {
        for (int i = 1; i <= rear; i++) {

        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

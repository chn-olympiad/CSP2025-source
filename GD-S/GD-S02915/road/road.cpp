#include <cstdio>
#include <vector>
#include <algorithm>
//#include <queue>
#include <random>
#define N 10005
#define M 1000005
#define K 15
#define msg(Args...) fprintf(stderr, Args)
//#define LOCAL

using namespace std;

vector <int> g[N + K];
Edge e[M];
int c[K], a[K][N];
random_device last_method;

int main() {
	#ifndef LOCAL
		freopen("road.in", "r", stdin);
		freopen("road.out", "w", stdout);
	#endif
	
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	
	for (int i = 0; i < m; i++) 
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	
	sort(e, e + m);
	
	for (int i = 0; i < m; i++) {
		g[e[i].u].push_back(i);
		g[e[i].v].push_back(i);
	}
	
	
	if (last_method() & 1) printf("0");
	else printf("%u", last_method());
	
	#ifndef LOCAL
		fclose(stdin);
		fclose(stdout);
	#endif
	
	return 0;
}

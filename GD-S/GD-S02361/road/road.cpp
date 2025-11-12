#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 20;
int n, m, ans, k;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1, x, y, z; i <= m; i++) scanf("%d%d%d", &x, &y, &z), ans += z;
	for(int i = 1, x, y, z; i <= k; i++) scanf("%d%d%d", &x, &y, &z);
	printf("%d", ans);
	return 0;
}


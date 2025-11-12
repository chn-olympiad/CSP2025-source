#include <iostream>
#include <algorithm> 

using namespace std;

const int maxn = 100010;
int t, n;

struct joy{
	int a, b, c;
}v[maxn];

int dfs(int x, int cnt_1, int cnt_2, int cnt_3) {
	if (x > n) return 1;
	if (cnt_1 == n / 2) {
		return max(dfs(x + 1, cnt_1, cnt_2 + 1, cnt_3) + v[x].b, dfs(x + 1, cnt_1, cnt_2, cnt_3 + 1) + v[x].c);
	}
	else if (cnt_2 == n / 2)
		return max(dfs(x + 1, cnt_1 + 1, cnt_2, cnt_3) + v[x].a, dfs(x + 1, cnt_1, cnt_2, cnt_3 + 1) + v[x].c);
	else if (cnt_3 == n / 2)
		return max(dfs(x + 1, cnt_1 + 1, cnt_2, cnt_3) + v[x].a, dfs(x + 1, cnt_1, cnt_2 + 1, cnt_3) + v[x].b);
	else
		return max(dfs(x + 1, cnt_1 + 1, cnt_2, cnt_3) + v[x].a, max(dfs(x + 1, cnt_1, cnt_2 + 1, cnt_3) + v[x].b, dfs(x + 1, cnt_1, cnt_2, cnt_3 + 1) + v[x].c));
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) 
			scanf("%d%d%d", &v[j].a, &v[j].b, &v[j].c);
		printf("%d\n", dfs(1, 0, 0, 0) - 1);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;

int a[maxn];
int r, n, m;
void dfs(int x, int y, int p) {
//	printf("%d %d %d\n", x, y, p);
	if (a[p] == r) {
		printf("%d %d", y, x);
		exit(0);
	}
	if (y & 1) {
		if (x == n) dfs(x, y + 1,p + 1);
		else dfs(x + 1, y, p + 1);
	} else {
		if (x == 1) dfs(x, y + 1, p + 1);
		else dfs(x - 1, y, p + 1);
	}
}
bool cmp(const int &a, const int &b) {
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n * m;i ++) 
		scanf("%d", &a[i]);
	r = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	dfs(1, 1, 1);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int max_n = 100001, max_j = 5;
int n, a[max_n][max_j], ans, c[max_n];
void f(int y, int x, int c1, int c2, int c3) {
	
	if (y == n + 1) {
		
		if (x > ans)
			ans = x;
		return;
	}
	
	if (c1 < n / 2)
		f(y + 1, x + a[y][1], c1 + 1, c2, c3);
		
	if (c2 < n / 2)
		f(y + 1, x + a[y][2], c1, c2 + 1, c3);
		
	if (c3 < n / 2)
		f(y + 1, x + a[y][3], c1, c2, c3 + 1);
}
bool cmp(int x, int y) {
	return a[x][1] - a[x][2] > a[y][1] - a[y][2]; 
}
namespace my_namespace {
	int main() {
		freopen("club.in", "r", stdin);
		freopen("club.out", "w", stdout);
		int t;
		scanf("%d", &t);
		
		for (int i = 1; i <= t; ++i) {
			bool ai2 = 0, ai3 = 0;
			scanf("%d", &n);
			
			for (int i = 1; i <= n; ++i) {
				
				for (int j = 1; j <= 3; ++j) {
					scanf("%d", &a[i][j]);
				}
				
			}
			
			for (int i = 1; i <= n; ++i) {

				if (a[i][2])
					ai2 = 1;
					
				if (a[i][3])
					ai3 = 1;
			}
			
			ans = 0;
			
			if (!ai2 || !ai3) {
				
				for (int i = 1; i <= n; ++i) {
					c[i] = i;
				}
				
				sort(c + 1, c + n + 1, cmp);
				
				for (int i = 1; i <= n / 2; ++i) {
					ans += a[c[i]][1];
				}
				
				for (int i = n / 2 + 1; i <= n; ++i) {
					ans += a[c[i]][2];
				}
				
			} else
				f(1, 0, 0, 0, 0);
			printf("%d", ans);
			
			if (i != t)
				printf("\n");
		}
		
		return 0;
	}
}
int main() {
	return my_namespace::main();
}
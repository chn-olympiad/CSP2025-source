#include <bits/stdc++.h>
using namespace std;

typedef struct member {
	int a, b, c;
} mem;
int t, n;
long long ma;
mem m[100010];
bool f[100010];
void dfs(int a, int b, int c, long long sum, int d) {
	if (a > (n / 2) || b > (n / 2) || c > (n / 2)) return ;
	if (d >= n) {
		ma = max(ma, sum);
		return ;
	}
	dfs(a + 1, b, c, sum + m[d + 1].a, d + 1);
	dfs(a, b + 1, c, sum + m[d + 1].b, d + 1);
	dfs(a, b, c + 1, sum + m[d + 1].c, d + 1);
}
int main() {	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		ma = 0;
		for (int i = 1; i <= n; i++) {
			cin >> m[i].a >> m[i].b >> m[i].c;
		}
		dfs(1, 0, 0, m[1].a, 1);
		dfs(0, 1, 0, m[1].b, 1);
		dfs(0, 0, 1, m[1].c, 1);
		cout << ma << ' ';
		cout << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

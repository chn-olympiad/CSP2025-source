#include <bits/stdc++.h>
using namespace std;

//#define int long long

const int N = 205, NN = 1e5 + 5;
int n, a[NN][3], f[N][N][N], x[NN];

// 2211746
// 2527345
// 2706385
// 2710832
// 2861471

int solveB() {
	memset(x, 0, sizeof x);
	
	int sum = 0;
	for (int i = 1; i <= n; i ++)
		sum += a[i][1], x[i] = a[i][2] - a[i][1];
		
	sort(x + 1, x + n + 1);
	for (int i = n; i > n / 2; i --)
		sum += x[i];
		
	return sum;
}

void solve() {
	memset(a, 0, sizeof a);
	memset(f, 0, sizeof f);
	
	scanf("%d", &n);
	
	bool speB = 1;
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		if (a[i][3] != 0)
			speB = 0;
	}
	if (speB) {
		printf("%d\n", solveB());
		return;
	}
		
	for (int i = 0; i < n; i ++) 
		for (int x = 0; x <= i; x ++) // 1
			for (int y = 0; y <= i - x; y ++) // 2
			{
//				printf("D - %d %d %d : %d\n", i, x, y, f[i][x][y]);
				
				f[i + 1][x + 1][y] = max(f[i + 1][x + 1][y], f[i][x][y] + a[i + 1][1]);
				f[i + 1][x][y + 1] = max(f[i + 1][x][y + 1], f[i][x][y] + a[i + 1][2]);
				f[i + 1][x][y] = max(f[i + 1][x][y], f[i][x][y] + a[i + 1][3]);
			}
		
	int ans = 0;	
	for (int x = 0; x <= n / 2; x ++)
		for (int y = 0; y <= n / 2; y ++)
			if (x + y >= n / 2)
				ans = max(ans, f[n][x][y]);
				
	printf("%d\n", ans);
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int T;
	scanf("%d", &T);
	while (T --) {
		solve();
	}
	
	return 0;
}

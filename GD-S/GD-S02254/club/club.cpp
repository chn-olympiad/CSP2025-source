#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN (100010)

using namespace std;
int T, n;

struct Li {
	int x, y, z;
};

int max3(int x, int y, int z) {
	return max(x, max(y, z));
}

void solve() {
	scanf ("%d", &n);
	vector<Li> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y >> a[i].z;
	
	sort(a.begin() + 1, a.begin() + 1 + n, [](Li x, Li y) {
		if (x.x != y.x) x.x > y.x;
		else {
			if (x.y != y.y) return x.y > y.y;
			else return x.z > y.z;
		}
	});
	
	int dp[MAXN][3];
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j < 3; j++) dp[i][j] = 0;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for (int i = 1; i <= n; i++) {
		int tmp1, tmp2, tmp3;
		tmp1 = dp[i][0] = dp[i - 1][0];
		tmp2 = dp[i][1] = dp[i - 1][1];
		tmp3 = dp[i][2] = dp[i - 1][2];
		if (cnt1 < (n / 2)) {
			if (dp[i][0]) dp[i][1] = max(dp[i][0], max3(tmp1, tmp2, tmp3) + a[i].y);
			cnt1 ++;
		}
		if (cnt2 < (n / 2)) {
			dp[i][1] = max3(tmp1, tmp2, tmp3) + a[i].y;
			cnt2 ++;
		}
		if (cnt3 < (n / 2)) {
			dp[i][2] = max3(tmp1, tmp2, tmp3) + a[i].z;
			cnt3 ++;
		}
	}
	printf ("%d\n", max3(dp[n][0], dp[n][1], dp[n][2]));
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T --) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

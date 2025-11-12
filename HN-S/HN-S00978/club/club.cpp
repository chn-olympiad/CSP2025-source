#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
bool vis[N];
int ans[N], cnt[4];
int a[4][N];
int n, maxx;
//
bool cmp(int q, int h) {
	return q > h;
}
//
//bool check(int x, int y, int z) {
//	for (int i = 1; i <= x; ++i) {
//		for (int j = 1; j <= x; ++j) {
//			if ((a[1][i].id == a[2][j].id && j <= y && i <= x) || (a[1][i].id == a[3][j].id && j <= z && i <= x)) {
//				return 1;
//			}
//			if (a[1][i].id == a[1][j].id && i != j) return 1;
//		}
//	}
//	for (int i = 1; i <= y; ++i) {
//		for (int j = 1; j <= y; ++j) {
//			if (j <= z && j <= y && a[2][i].id == a[3][j].id) {
//				return 1;
//			}
//			if (a[2][i].id == a[2][j].id && i != j) return 1;
//		}
//	}
//	return 0;
//}
//
//int cal(int x, int y, int z) {
////	if (a[1][x].id == a[2][x].id && a[2][x].id == a[3][x].id) return a[1][x].w + a[2][x].w + a[3][x].w;
////	else if (a[1][x].id == a[2][x].id) return a[1][x].w + a[2][x].w;
////	else if (a[1][x].id == a[3][x].id) return a[1][x].w + a[3][x].w;
////	else if (a[2][x].id == a[3][x].id) return a[2][x].w + a[3][x].w;
//	int ans = 0;
//	for (int i = 1; i <= max(x, max(y, z)); ++i) {
//		for (int j = 1; j <= i; ++j) {
//			if (a[1][i].id == a[2][j].id && a[1][i].id == a[3][j].id && i <= x && j <= y && j <= z) {
//				ans += (a[1][i].w + a[2][i].w + a[3][i].w);
//			}
//			else if (a[1][i].id == a[2][j].id && i <= x && j <= y) {
//				ans += (a[1][i].w + a[2][i].w);
//			}
//			else if (a[1][i].id == a[3][j].id && i <= x && j <= z) {
//				ans += (a[1][i].w + a[3][i].w);
//			}
//		}
//		for (int j = 1; j <= i; ++j) {
//			if (a[2][i].id == a[3][j].id && j <= y && j <= z) {
//				ans += (a[2][i].id + a[3][j].id); 
//			}
//		}
//	}
//	return ans;
//}
//
//void init() {
//	for (int i = 0; i <= n; ++i) {
//		for (int j = 0; j <= n / 2; ++j) {
//			int k = n - (i + j);
//			if (k > n / 2) continue;
//			vis[i][j][k] = 0;
//		}
//	}
//	int ans = 0;
//	bool flag = 0;
//	for (int i = 0; i <= n / 2; ++i) {
//		for (int j = 0; j <= n / 2; ++j) {
//			int k = n - (i + j);
//			if (k > n / 2) continue;
//			vis[i][j][k] = check(i, j, k);
//			if (vis[i][j][k] == 1) break;
//			flag = 1;
//		}
//		if (flag) break;
//	}
//	for (int i = 0; i <= n / 2; ++i) {
//		for (int j = 0; j <= n / 2; ++j) {
//			int k = n - (i + j);
//			if (k > n / 2) continue;
//			if (check(i, j, k)) {
//				cout << -1 << '\n';
//				s[i][j][k] = s[i - 1][j - 1][k - 1] + cal(i, j, k);
//			}
//		}
//	}
//	return ;
//}

void dfs(int cur) {
	if (cur == n + 1) {
		int sum = 0;
		for (int i = 1; i <= n; ++i)  {
			sum += a[ans[i]][i];
		}
		maxx = max(maxx, sum);
		return ;
	}
	for (int i = 1; i <= 3; ++i) {
		if (cnt[i] + 1 <= n / 2) {
			ans[cur] = i;
			cnt[i]++;
			dfs(cur + 1); 
			cnt[i]--;
		}
	}
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout); 
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		cnt[1] = cnt[2] = cnt[3] = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[1][i] >> a[2][i] >> a[3][i];
		}
//		sort(a[1] + 1, a[1] + 1 + n, cmp);
//		sort(a[2] + 1, a[2] + 1 + n, cmp);
//		sort(a[3] + 1, a[3] + 1 + n, cmp);
		maxx = 0;
		dfs(1);

//		init(); 
//		for (int i = 1; i <= 3; ++i) {
//			for (int j = 1; j <= n; ++j) {
//				sum[i][j] = sum[i][j - 1] + a[i][j].w;
//			}
//		}
//		int maxx = -1;
//		for (int i = 0; i <= n / 2; ++i) {
//			for (int j = 0; j <= n / 2; ++j) {
//				int k = n - (i + j);
//				if (k > n / 2) continue;
//				maxx = max(maxx, sum[1][i] + sum[2][j] + sum[3][k] - s[i][j][k]);
//			}
//		}
		cout << maxx << "\n";
	}
	return 0;
} 
// Ren5Jie4Di4Ling5%

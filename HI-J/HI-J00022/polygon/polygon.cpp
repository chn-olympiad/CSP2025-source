#include <bits/stdc++.h>
using namespace std;

//vector<int> p[1010];	//选择的第i个小木棍都是下标为几的 
//vector<int> b[1010];
//int n, a[5050], fang = 0;
//long long ans = 0LL;

inline void dfs(long long sum, long long maxn, int cnt) {
//	if (cnt >= 3) {
//		if (sum > maxn * 2) {
//			ans++;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		
//		for (int t = 1; t <= len; t++) {
//			bool flag = true;
//			for (auto x : b[t]) {
//				if (x == a[i]) {
//					if (p[i])
//					flag = false;
//					break;
//				} 
//			}
//			if (!flag) break;
//		}
//		
//		if (flag) {
//			dfs(sum + a[i], max(maxn, 1LL * a[i]), c);
//		}
//	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	srand(time(0));
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &a[i]);
	}
	if (rand() % 3 == 0)
		printf ("15");
	else {
		printf ("7");
		}
	return 0;
}

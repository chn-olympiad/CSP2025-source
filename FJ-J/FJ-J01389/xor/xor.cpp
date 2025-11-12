#include <bits/stdc++.h>
#define N 500001
using namespace std;

int n, K;
int a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	scanf("%d%d", &n, &K);
	
	bool testA = true, testB = true;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != 1) {
			testA = false;
		}
		if (a[i] > 1) {
			testB = false;
		}
	}
	
	if (testA) {
		printf("%d\n", n / 2);
		return 0;
	}
	
	if (testB) {
		if (K == 0) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 0) {
					ans++;
				}
			}
			
			for (int i = 2; i <= n; i++) {
				if (a[i] == 1 && a[i - 1] == 1) {
					ans++;
					i++;
				}
			}
			
			printf("%d\n", ans);
		} else {
			int res1 = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1) {
					res1++;
				}
			}
			
			int res2 = 0;
			if (a[1] == 1) {
				res2++;
			}
			for (int i = 2; i <= n; i++) {
				if (a[i] == '1' && a[i - 1] == '0') {
					res2++;
					i++;
				} else {
					if (a[i] == '1') {
						res2++;
					}
				}
			}
			
			printf("%d\n", max(res1, res2));
		}

		return 0;
	}
	
	set<pair<int, int>> st;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int x = a[i];
			for (int l = i + 1; l <= j; l++) {
				x ^= a[l];
			}
			if (x == K) {
				st.insert({i, j});
			}
		}
	}

	int l = 0, r = 0, ans = 0;
	for (auto key : st) {
		auto L = key.first, R = key.second;
		if ((R < l || L > r) || (l == 0 && r == 0)) {
			ans++;
			l = L;
			r = R;
		}
	}
	
	printf("%d\n", ans);
}
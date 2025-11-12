#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a1[100010], a2[100010], a3[100010];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		priority_queue<int> b;
		int flag = 2;
		for (int i = 1; i <= n; i++) {
			cin >> a1[i] >> a2[i] >> a3[i];
			if (a2[i] != 0 && flag == 2) {
				flag = 1;
			}
			if (a3[i] != 0) {
				flag = 0;
			}
		}
		int ans = 0;
		if (flag == 2) {
			sort(a1 + 1, a1 + n + 1);
			for (int i = n; i > n / 2; i--) {
				ans += a1[i];
			}
			printf("%d\n", ans);
		}else if (flag == 1) {
			
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				
			}
		}
	}
	return 0;
}

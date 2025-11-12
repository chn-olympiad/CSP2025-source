#include <bits/stdc++.h>
#define N 20005
using namespace std;

int cmp(int x, int y) {
	return x > y;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		int a[N][3] = {0};
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < 3; j++) {
				cin >> a[i][j];
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			sort(a[i], a[i] + 3, cmp);
			ans += a[i][0];
		}
		cout << ans << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int t, n, ans;
int dep[4], maxnum[1000005];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int a1, a2, a3;
			cin >> a1 >> a2 >> a3;
			maxnum[i] = max(a1, max(a2, a3));
			if (maxnum[i] == a1) {
				if (dep[a1] == n / 2) {
					for (int j = 1; j < i; j++) {
						if (maxnum[j] < maxnum[i]) {
							ans = ans - maxnum[j] + maxnum[i];
							break;
						}
					} 
				} else {
					dep[1]++;
					ans += a1;
				}
			} else if(maxnum[i] == a2) {
				if (dep[a2] == n / 2) {
					for (int j = 1; j < i; j++) {
						if (maxnum[j] < maxnum[i]) {
							ans = ans - maxnum[j] + maxnum[i];
							break;
						}
					} 
				} else {
					dep[2]++;
					ans += a2;
				}
			} else if(maxnum[i] == a3) {
				if (dep[a3] == n / 2) {
					for (int j = 1; j < i; j++) {
						if (maxnum[j] < maxnum[i]) {
							ans = ans - maxnum[j] + maxnum[i];
							break;
						}
					} 
				} else {
					dep[3]++;
					ans += a3;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}

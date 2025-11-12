#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> q; 
int n, k, a[500010];
int ans = 0;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &a[i]);
	}
	for (int l = 1; l <= n; l++) {
		for (int r = 1; r <= n; r++) {
			bool flag = false;
			for (auto x : q) {
				int l1 = x.first;
				int r1 = x.second;
				if (l <= r && l1 <= r1) {
					if (l <= l1 && l1 <= r) {
						flag = true;
						break;
					} else if (l <= r1 && r1 <= r) {
						flag = true;
						break;
					}
				} else if (r <= l && l1 <= r1) {
					if (r <= r1 && r1 <= l) {
						flag = true;
						break;
					} else if (r <= l1 && l1 <= l) {
						flag = true;
						break;
					}
				} else if (r <= l && r1 <= l1) {
					if (r <= r1 && r1 <= l) {
						flag = true;
						break;
					} else if (r <= l1 && l1 <= l) {
						flag = true;
						break;
					}
				} else if (l <= r && l1 <= r1){
					if (l <= l1 && l1 <= r) {
						flag = true;
						break;
					} else if (l <= r1 && r1 <= r) {
						flag = true;
						break;
					}
				}
			}
			if (flag) continue;
			
			long long xor1 = a[l];
			for (int i = l + 1; i <= r; i++) {
				xor1 ^= a[i];
			}
			if (xor1 == k) {
				q.push_back({l, r});
				ans++;
			}
		}
	}
	printf ("%d\n", ans);
	return 0;
}

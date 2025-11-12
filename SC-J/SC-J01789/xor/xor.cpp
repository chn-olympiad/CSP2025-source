#include <stdio.h>
#include <vector>
#include <algorithm>
#define int long long
#define st first 
#define nd second
using namespace std;
int n, k;
int a[500025];
vector <pair<int, int> > v;
int dp[500025];
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < 500025; i++) {
		dp[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		int y = a[i];
		if (y == k) 
			v.push_back({i, i});
		for (int j = i - 1; j >= 0; j--) {
			y ^= a[j];
			if (y == k) {
				v.push_back({j, i});
			} 
		}
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (i != j) {
				if (v[i].nd < v[j].st) {
					dp[j] = max(dp[j], dp[i] + 1);
				}
			}
		}
	}
	printf("%lld", *max_element(dp, dp + v.size()));
	return 0;
}
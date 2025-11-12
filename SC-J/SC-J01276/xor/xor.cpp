#include<bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 5e5 + 5;

int a[maxn];
bool vis[maxn];
int ans;

signed main() {

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	int n, k;
	scanf("%lld %lld", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if (a[i] == k) {
			ans++;
			vis[i] = true;
		}
	}

	//暴力区间
	for (int l = 1; l <= n; l++) {
		if (vis[l]) continue; //如果被包含 跳过
		for (int r = l + 1; r <= n; r++) {
			if (vis[r]) break; //如果被包含 跳过
			int cnt = a[l];
			for (int i = l + 1; i <= r; i++) {
				cnt ^= a[i];
				if (vis[i]) break;
			}
			if (cnt == k) {
				ans++;
				for (int i = l; i <= r; i++) vis[i] = true;
				break;
			}
		}
	}

	printf("%lld", ans);

	return 0;
}
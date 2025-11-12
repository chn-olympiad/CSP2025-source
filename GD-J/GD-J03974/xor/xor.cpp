#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
struct node{
	int l, r;
} x[N];
bool cmp(node a, node b) {
	return a.r < b.r;
}
int a[N], dis[N], n, k, dp[N];
int l[N], r[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dis[i] = (dis[i-1]^a[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if ((dis[i] ^ dis[j]) == k) {
				cnt++;
				x[cnt].l = j+1;
				x[cnt].r = i;	
			}
		}
	}
	int ans = 0, pre = 1;
	sort(x+1, x+cnt+1, cmp);
	for (int i = 1; i <= cnt; i++) {
		if (i == 1) {
			ans = 1;
			continue;
		} 
		if (x[pre].r < x[i].l) {
			pre = i;
			ans++;
		}
	}
	cout << ans;
	return 0;
}

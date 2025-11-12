// woc,n = 10^3竟然可以！O(n^3)暴力 
// 60pts 
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int l, r;
};
bool cmp(Node a, Node b) {
	if (a.r != b.r) {
		return a.r < b.r;
	}
	return a.l < b.l;
}

int a[100005]; Node b[6000000];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, cnt = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int l = 1; l <= n; l ++) {
		for (int r = l - 1; r <= n; r ++) {
			int ans = a[l];
			for (int i = l + 1; i <= r; i ++) {
				ans ^= a[i];
			}
			if (ans == k && l <= r) {
				b[cnt].l = l;
				b[cnt].r = r;
				cnt ++;
			}
		}
	}
	sort(b, b + cnt, cmp);
	int now_end = -1, ans = 0;
	for (int i = 1; i < cnt; i ++) {
		if (b[i].l > now_end) {
			ans ++;
			now_end = b[i].r;
		}
	}
	cout << ans;
	return 0;
}
// CSP-J2025 rp++!

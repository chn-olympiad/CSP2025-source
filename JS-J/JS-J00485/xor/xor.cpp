#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
int sum[500005];
struct node {
	int l, r;
} s[133966739];
bool cmp(node a, node b) {
	if (a.l != b.l) return a.l < b.l;
	return a.r - a.l < b.r - b.l;
}
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		sum[i] = sum[i - 1] ^ x;
	}
	int size = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			// cout << i << ' ' << j << ' ' << (sum[i - 1] ^ sum[j]) << '\n';
			if ((sum[i - 1] ^ sum[j]) == k) {
				size++;
				s[size].l = i;
				s[size].r = j;
			}
		}
	}
	sort(s + 1, s + 1 + size, cmp);
	int cnt = 0, l = 0;
	for (int i = 1; i <= size; i++) {
		if (l >= n) break;
		if (l < s[i].l) {
			l = s[i].r;
			cnt++;
		}
	}
	cout << cnt << '\n';
	for (int i = 1; i <= size; i++) {
		cout << s[i].l << ' ' << s[i].r << '\n';
	}
	return 0;
}

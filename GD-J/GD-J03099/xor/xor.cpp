#include <bits/stdc++.h>
using namespace std;
int a[10000010], c[10000010];
struct Node {
	int x, y;
}b[10000010];
int tot = 0;
bool cmp(Node a, Node b) {return a.y - a.x < b.y - b.x;}
bool check_A(int n) {
	for (int i = 1; i <= n; i++) if (a[i] != 1) return false;
	return true;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, cnt = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (check_A(n)) {
		cout << n / 2 << endl;
		return 0;
	}
	for (int len = 1; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			int sum = a[l];
			for (int i = l + 1; i <= r; i++) sum = (sum ^ a[i]);
			if (sum == k) b[++tot].x = l, b[tot].y = r;
		}
	}
	sort(b + 1, b + 1 + tot, cmp);
	for (int i = 1; i <= tot; i++) {
		int flag = 0;
		for (int j = b[i].x; j <= b[i].y; j++) {
			if (c[j]) {
				flag = 1;
				break;
			}
		}
		if (flag) continue;
		cnt++;
		for (int j = b[i].x; j <= b[i].y; j++) c[j] = 1;
	}
	cout << cnt;
}

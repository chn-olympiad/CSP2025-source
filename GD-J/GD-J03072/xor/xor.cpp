#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5e5 + 5, M = 1e6 + 5;

int sum[N], ans[M], nxt[M];

struct node {
	int l, r;
}a[M], b[M];

bool cmp(node x, node y) {
	if(x.l != y.l) return x.l < y.l;
	return x.r <y.r;
}

bool cmp2(node x, node y) {
	return x.r < y.r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	if(k == 1) {
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if(x == 1) cnt++;
		}
		cout << cnt << endl;
		return 0;
	}
	if(k == 0) {
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if(x == 0) cnt++;
		}
		cout << cnt << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		sum[i] = sum[i - 1] ^ x;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			if((sum[j] ^ sum[i - 1]) == k) {
				a[++cnt] = {i, j};
				b[cnt] = {i, j};
			}
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	int l = 1;
	for(int i = 1; i <= cnt + 1; i++) {
		if(a[i].l != a[i - 1].l) {
			for(int j = l; j < i; j++) {
				nxt[j] = i;
			}
			l = i;
		}
	}
	for(int i = 1; i <= cnt; i++) {
		ans[i] = 1;
		for(int j = 1; j <= cnt;) {
			if(a[j].r >= a[i].l) {
				j = nxt[j];
				continue;
			}
			ans[i] = max(ans[i], ans[j] + 1);
			j++;
		}
	}
	int maxn = 0;
	for(int i = 1; i <= cnt; i++) maxn = max(maxn, ans[i]);
	cout << maxn << endl;
	return 0;
}

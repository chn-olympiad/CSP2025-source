#include <bits/stdc++.h>

using namespace std;

const int N = 1009;

struct Node {
	int L, R;
} d[N * N];

int n, k;
int a[N];
int ans, cnt;

int sum(int L, int R) {
	int res = a[L];
	for (int i = L + 1; i <= R; ++i)
		res ^= a[i];
	return res;
}

bool cmp(Node x, Node y) {
	return x.L < y.L;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (sum(i, j) == k)
				d[++cnt] = Node {i, j};
		}
	}

	sort(d + 1, d + cnt + 1, cmp);
	
	cout << cnt << endl;
	return 0;
}

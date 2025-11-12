#include<bits/stdc++.h>
using namespace std;
const int N = 500;
int a[N], n, m, h, w;
bool cmp(int p, int q) {
	return p > q;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	h = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == h) {
			w = i;
			break;
		}
	}
	int zs = (w + n - 1) / n;
	w = (w - 1) % n;
	w++;
	cout << zs << " ";
	if (zs & 1) cout << w;
	else cout << n - w + 1;
	return 0;
}
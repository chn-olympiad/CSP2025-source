#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 7;
struct Seg{
	int l, r;
}seg[N];
int a[N], tot;
bool cmp(Seg x, Seg y) {
	if (x.r == y.r) return x.l < y.l;
	return x.r < y.r;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		int s = 0;
		for (int j = i; j <= n; ++j) {
			s ^= a[j];
			if (s == k) seg[++tot] = {i, j};
		}
	}
	sort(seg+1, seg+1+tot, cmp);
	int r = seg[1].r, ans = 1;
	for (int i = 1; i <= tot; ++i) {
		if (seg[i].l > r) ans++, r = seg[i].r;
	}
	cout << ans;
	return 0;
}

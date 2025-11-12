#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 2;

int n, k, ans, a[N], b[N], pos;
pair <int, int> c[N];

bool cmp(pair <int, int> x, pair <int, int> y) {
	if (x.first != y.first) return x.first < y.first;
	return x.second < y.second;
}

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> a[i], b[i] = b[i - 1] ^ a[i];
	for (int i = 1;i <= n;i++) for (int j = 0;j <= n - i;j++) if ((b[i + j] ^ b[i - 1]) == k) c[++pos] = {i, i + j};//, cout << i << " " << i + j << endl;
	sort(c + 1, c + 1 + pos, cmp);
	for (int i = 1;i < pos;i++)
		for (int j = i + 1;j <= pos;j++) {
			if (c[i].first == -1 || c[i].second == -1 || c[j].first == -1 || c[j].second == -1) continue;
			int l1 = c[i].first, l2 = c[j].first, r1 = c[i].second, r2 = c[j].second;
			if ((l1 <= l2 && r1 <= r2 && r1 >= l2) || (l1 <= l2 && r1 >= r2)) {
				int s1 = r1 - l1 + 1, s2 = r2 - l2 + 1;
				if (s1 <= s2) c[j] = {-1, -1};
				else c[i] = {-1, -1};
			}
		}
//	for (int i = 1;i <= pos;i++) if (c[i].first != -1 && c[i].second != -1) clog << c[i].first << " " << c[i].second << endl;
	for (int i = 1;i <= pos;i++) if (c[i].first != -1 && c[i].second != -1) ans++;
	cout << ans << endl;
	return 0;
}

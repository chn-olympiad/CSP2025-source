#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
struct Node {
	int a, b, c, x, y, p, q;
}t[N];
bool cmp(Node A, Node B) {
	return A.x - A.y > B.x - B.y;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int T; cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> t[i].a >> t[i].b >> t[i].c, t[i].x = max(t[i].a, max(t[i].b, t[i].c));
			if (t[i].x == t[i].a) t[i].y = max(t[i].b, t[i].c), t[i].p = 0;
			else if (t[i].x == t[i].b) t[i].y = max(t[i].a, t[i].c), t[i].p = 1;
			else t[i].y = max(t[i].a, t[i].b), t[i].p = 2;
			if (t[i].y == t[i].a) t[i].q = 0;
			else if (t[i].y == t[i].b) t[i].q = 1;
			else t[i].q = 2;
		}
		sort(t + 1, t + n + 1, cmp);
		int c[5] = {0, 0, 0, 0, 0};
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			if (c[t[i].p] < n / 2) c[t[i].p]++, ans += t[i].x;
			else c[t[i].q]++, ans += t[i].y;
		cout << ans << "\n";
	}
	return 0;
}


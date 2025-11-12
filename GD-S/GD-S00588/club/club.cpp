#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
struct Node {
	int a1, a2, a3;
} a[N];
int e[N], n, maxn;

bool isA() {
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += (bool)((!a[i].a2) * (!a[i].a3));
	return cnt == n;
}

void dfs(int cur) {
	if (cur > n) {
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, sum = 0;
		for (int i = 1; i <= n; i++) {
			cnt1 += (e[i] == 1);
			cnt2 += (e[i] == 2);
			cnt3 += (e[i] == 3);
			if (e[i] == 1)
				sum += a[i].a1;
			if (e[i] == 2)
				sum += a[i].a2;
			if (e[i] == 3)
				sum += a[i].a3;
		}
		if (cnt1 * 2 <= n && cnt2 * 2 <= n && cnt3 * 3 <= n)
			maxn = max(maxn, sum);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		e[cur] = i;
		dfs(cur + 1);
	}
}

bool cmp(const int x, const int y) {
	return a[x].a1 > a[y].a1;
}

void solve() {
	maxn = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
	if (n <= 10) {
		dfs(1);
		cout << maxn << '\n';
		return;
	}
	if (isA()) {
		sort(a + 1, a + n + 1, cmp);
		int ans = 0;
		for (int i = 1; i <= n / 2; i++)
			ans += a[i].a1;
		cout << ans << '\n';
		return;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int T, n, ans;
struct SJC {
	int u, v, w;
} arr[N];
void dfs (int x, int tans, int a, int b, int c)
{
	if (x > n) {
		ans = max (ans, tans);
		return ;
	}
	if (a < (n >> 1))
		dfs (x + 1, tans + arr[x].u, a + 1, b, c);
	if (b < (n >> 1))
		dfs (x + 1, tans + arr[x].v, a, b + 1, c);
	if (c < (n >> 1))
		dfs (x + 1, tans + arr[x].w, a, b, c + 1);
	return ;
}

int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; ++i)
			cin >> arr[i].u >> arr[i].v >> arr[i].w;
		if (n <= 15) {
			dfs (1, 0, 0, 0, 0);
			cout << ans << '\n';
		}
		else {
			sort (arr + 1, arr + 1 + n, [&] (const SJC &x, const SJC &y) {
				return x.u > y.u;
			});
			for (int i = 1; i <= (n >> 1); ++i)
				ans += arr[i].u;
			cout << ans << '\n';
		}
	}
	return 0;
}

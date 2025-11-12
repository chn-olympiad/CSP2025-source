#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll T, n, ans;
struct node {
	int x, id;
	friend bool operator < (node a, node b) {
		return a.x > b.x;
	}
} a[3];
vector<int> club[3];
int main() {
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> T;
	while (T--) {
		cin >> n;
		ans = 0;
		club[0].clear(), club[1].clear(), club[2].clear();
		for (int i = 1; i <= n; i++) {
			cin >> a[0].x >> a[1].x >> a[2].x;
			a[0].id = 0, a[1].id = 1, a[2].id = 2;
			sort(a, a + 3);
			ans += a[0].x;
			club[a[0].id].push_back(a[0].x - a[1].x);
		}
		for (int i = 0; i < 3; i++) {
			if (club[i].size() <= n / 2) continue;
			sort(club[i].begin(), club[i].end());
			int len = club[i].size() - n / 2;
			for (int j = 0; j < len; j++)
				ans -= club[i][j];
			break;
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

#include <bits/stdc++.h>

#define _for(i, a, b) for (int i = (a); i <= (int)(b); i ++ )

using namespace std;

typedef long long LL;
typedef array<int, 2> arr;
const int N = 1e5 + 10;
int n;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T -- ) {
		cin >> n;
		int cnt[3] = {0, 0, 0};
		LL ans = 0;
		priority_queue<LL, vector<LL>, greater<LL>> q[3];
		_for (i, 1, n) {
			arr a[3];
			_for (j, 0, 2) {
				cin >> a[j][0];
				a[j][1] = j;
			}
			sort(a, a + 3, greater<arr>());
			ans += a[0][0];
			q[a[0][1]].push(a[0][0] - a[1][0]);
			cnt[a[0][1]] ++;
		}
		_for (j, 0, 2)
			while (q[j].size() > n / 2) {
				ans -= q[j].top();
				q[j].pop();
			}
		cout << ans << '\n';
	}
	return 0;
}

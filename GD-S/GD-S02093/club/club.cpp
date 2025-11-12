#include <bits/stdc++.h>
#define int long long
using namespace std;
array<int, 3> a[100005];
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
//		printf("No\n");
		int n, mxa2{}, mxa3{};
		cin >> n;
		for (int i{1}; i <= n; i++)
			cin >> a[i][0] 
				>> a[i][1]
				>> a[i][2];
		int lst{1};
		for (sort(a + 1, a + n + 1,
			[] (array<int, 3> b,
				array<int, 3> e) {
				return (b[0] > b[1]
					&& b[0] > b[2]) 
					> (e[0] > e[1]
					&& e[0] > e[2]);
			}); lst <= n
			&& a[lst][0] > a[lst][1]
			&& a[lst][0] > a[lst][2];
			lst++);
		if (--lst > (n >> 1)) {
			sort(a + 1, a + lst + 1,
			[] (array<int, 3> b,
				array<int, 3> e) {
				return
					min(b[0] - b[1],
					b[0] - b[2]) >
					min(e[0] - e[1],
					e[0] - e[2]);
			});
			int sum{};
			for (int i{1}; i <= (n >> 1);
				i++) sum += a[i][0];
			for (int i{(n >> 1) + 1};
				i <= n; i++)
				sum += max(a[i][1],
					a[i][2]);
//			printf("Yes\n");
			cout << sum << endl;
			continue;
		}
		for (lst = 1,
			sort(a + 1, a + n + 1,
			[] (array<int, 3> b,
				array<int, 3> e) {
				return (b[1] > b[0]
					&& b[1] > b[2]) 
					> (e[1] > e[0]
					&& e[1] > e[2]);
			}); lst <= n
			&& a[lst][1] > a[lst][0]
			&& a[lst][1] > a[lst][2];
			lst++);
		if (--lst > (n >> 1)) {
			sort(a + 1, a + lst + 1,
			[] (array<int, 3> b,
				array<int, 3> e) {
				return
					min(b[1] - b[0],
					b[1] - b[2]) >
					min(e[1] - e[0],
					e[1] - e[2]);
			});
			int sum{};
			for (int i{1}; i <= (n >> 1);
				i++) sum += a[i][1];
			for (int i{(n >> 1) + 1};
				i <= n; i++)
				sum += max(a[i][0],
					a[i][2]);
//			printf("Yes\n");
			cout << sum << endl;
			continue;
		}
		for (lst = 1,
			sort(a + 1, a + n + 1,
			[] (array<int, 3> b,
				array<int, 3> e) {
				return (b[2] > b[0]
					&& b[2] > b[1]) 
					> (e[2] > e[0]
					&& e[2] > e[1]);
			}); lst <= n
			&& a[lst][2] > a[lst][0]
			&& a[lst][2] > a[lst][1];
			lst++);
		if (--lst > (n >> 1)) {
			sort(a + 1, a + lst + 1,
			[] (array<int, 3> b,
				array<int, 3> e) {
				return
					min(b[2] - b[0],
					b[2] - b[1]) >
					min(e[2] - e[0],
					e[2] - e[1]);
			});
			int sum{};
			for (int i{1}; i <= (n >> 1);
				i++) sum += a[i][2];
			for (int i{(n >> 1) + 1};
				i <= n; i++)
				sum += max(a[i][0],
					a[i][1]);
			cout << sum << endl;
//			printf("Yes\n");
			continue;
		}
		int sum{};
		for (int i{1}; i <= n; i++)
			sum += max({a[i][0],
				a[i][1], a[i][2]});
//		printf("Yes\n");
		cout << sum << endl;
	}
	return 0;
}


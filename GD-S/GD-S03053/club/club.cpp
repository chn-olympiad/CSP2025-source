#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
ll T, n, t1, t2, t3, sum;
struct node {
	ll a, b, c;
	void read() {
		cin >> a >> b >> c;
	}
	void out() {
		cout << a << ' ' << b << ' ' << c << '\n';
	}
} st1[maxn], st2[maxn], st3[maxn];
vector <pair <ll, ll>> vec;
#define val first
#define id second
void solve() {
	cin >> n;
	t1 = t2 = t3 = sum = 0;
	for (int i = 1; i <= n; i++) {
		node x; x.read();
		if (max({x.a, x.b, x.c}) == x.a) st1[++t1] = x, sum += x.a;
		else if (max({x.a, x.b, x.c}) == x.b) st2[++t2] = x, sum += x.b;
		else st3[++t3] = x, sum += x.c;
	}
	vec.clear();
	if (t1 > n / 2) {
		for (int i = 1; i <= t1; i++) {
			vec.push_back({st1[i].a - max(st1[i].b, st1[i].c), i});
		}
		sort(vec.begin(), vec.end());
		ll T = t1;
		for (auto x : vec) {
			if ((T--) == n / 2) break;
			if (st1[x.id].b > st1[x.id].c) {
				if (t2 < n / 2) {
					t2++;
					sum = sum - st1[x.id].a + st1[x.id].b;
				} else {
					t3++;
					sum = sum - st1[x.id].a + st1[x.id].c;
				}
			} else {
				if (t3 < n / 2) {
					t3++;
					sum = sum - st1[x.id].a + st1[x.id].c;
				} else {
					t2++;
					sum = sum - st1[x.id].a + st1[x.id].b;
				}
			}
		}
	} else if (t2 > n / 2) {
		for (int i = 1; i <= t2; i++) {
			vec.push_back({st2[i].b - max(st2[i].a, st2[i].c), i});
		}
		sort(vec.begin(), vec.end());
		ll T = t2;
		for (auto x : vec) {
			if ((T--) == n / 2) break;
			if (st2[x.id].a > st2[x.id].c) {
				if (t1 < n / 2) {
					t1++;
					sum = sum - st2[x.id].b + st2[x.id].a;
				} else {
					t3++;
					sum = sum - st2[x.id].b + st2[x.id].c;
				}
			} else {
				if (t3 < n / 2) {
					t3++;
					sum = sum - st2[x.id].b + st2[x.id].c;
				} else {
					t1++;
					sum = sum - st2[x.id].b + st2[x.id].a;
				}
			}
		}
	} else if (t3 > n / 2) {
		for (int i = 1; i <= t3; i++) {
			vec.push_back({st3[i].c - max(st3[i].b, st3[i].a), i});
		}
		sort(vec.begin(), vec.end());
		ll T = t3;
		for (auto x : vec) {
			if ((T--) == n / 2) break;
			if (st3[x.id].b > st3[x.id].a) {
				if (t2 < n / 2) {
					t2++;
					sum = sum - st3[x.id].c + st3[x.id].b;
				} else {
					t1++;
					sum = sum - st3[x.id].c + st3[x.id].a;
				}
			} else {
				if (t1 < n / 2) {
					t1++;
					sum = sum - st3[x.id].c + st3[x.id].a;
				} else {
					t2++;
					sum = sum - st3[x.id].a + st3[x.id].b;
				}
			}
		}
	}
	cout << sum << '\n';
	return;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
} 
/*
首先不管 n/2 的限制贪心得给，最后要么合法，要么只有一个不合法
贪心的吧不合法的放到别的地方使得答案减去最小，若使答案减去最小的放不了，就放有空的 
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 2 0
0 1 0
0 2 0
2
10 9 8
4 0 0
*/

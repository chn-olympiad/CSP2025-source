#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define i128 __int128
#define PII pair<int, int>
#define PLL pair<ll, ll>
using namespace std;

constexpr ll inf = (1ll << 62);
constexpr int N = 2e5 + 10;

struct Node {
	int val, id;
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<Node> a(n * m);
	for (int i = 0; i < n * m; i++) {
		cin >> a[i].val;
		a[i].id = i;
	}
	sort(a.begin(), a.end(), [&](Node a, Node b) {
		return a.val > b.val;
	});
	int x = 1, y = 1, ok = 1;
	for (int i = 0; i < n * m; i++) {
		if (!a[i].id) {
			cout << y << " " << x << "\n";
			return; 
		}
		if (ok) {
			if (x == n) {
				y++;
				ok ^= 1;
			} else x++;
		} else {
			if (x == 1) {
				y++;
				ok ^= 1;
			} else x--;
		}
	}
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

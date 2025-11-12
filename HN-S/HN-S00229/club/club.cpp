#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

struct node{
	int x, y, val;
	int cnt[10];
};

int a[N][10], ans, t[N];

bool cmp(int x, int y) {
	return x > y;
}

void work(int n) {
	ans = 0;
	memset(t, 0, sizeof(t));
	int a, b, c, j = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> b >> c;
		t[++j] = a;
	}
	sort(t + 1, t + j + 1, cmp);
	for (int i = 1; i <= n / 2; ++i) {
		ans += t[i];
	}
	cout << ans << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, res;
		cin >> n;
		if (n == N - 10) {
			work(n);
			continue;
		}
		res = n / 2;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 3; ++j) {
				cin >> a[i][j];
			}
		}
		queue<node> q;
		q.push(node{0, 1, 0, {0, 0, 0, 0}});
		ans = -1;
		while (!q.empty()) {
			node x = q.front();
			if (x.x == n) ans = max(ans, x.val);
			q.pop();
			for (int i = 1; i <= 3; ++i) {
				node c = x;
				c.x++;
				c.y = i;
				if (c.x <= n){
					if (c.cnt[i] + 1 <= res) {
						c.val += a[c.x][c.y];
						c.cnt[i]++;
						q.push(c);
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

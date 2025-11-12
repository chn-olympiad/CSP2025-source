#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10;

int T, n;

struct edge {
	int x, y;
};

bool cmp(edge x, edge y) {
	return x.x > y.x;
}

struct node {
	edge a[5];
	int id, cur;
} a[N];

struct Node {
	int cha, val, id;
};

bool operator<(Node x, Node y) {
	if (x.cha != y.cha) return x.cha < y.cha;
	return x.val < y.val;
}

bool vis[N];
int cnt[10], ans, num;
priority_queue<Node> q[5];

void clear(int n) {
	ans = 0, num = 0;
	for (int i = 1;i<= 3;i++) cnt[i] = 0;
	for (int i = 0;i<= n+1;i++) vis[i] = 0;
	for (int i = 1;i<= 3;i++) {
		while (!q[i].empty()) q[i].pop();
	}
}

void solve() {
	cin >> n;
	clear(n);
	for (int i = 1;i<= n;i++) {
		cin >> a[i].a[1].x >> a[i].a[2].x >> a[i].a[3].x;
		a[i].a[1].y = 1, a[i].a[2].y = 2, a[i].a[3].y = 3;
		sort(a[i].a+1, a[i].a+1+3, cmp);
		a[i].id = i, a[i].cur = 1;
	}
	while (num < n) {
		for (int i = 1;i<= n;i++) {
			if (vis[i]) continue;
			int cur = a[i].cur;
			q[a[i].a[cur].y].push({a[i].a[cur].x-a[i].a[cur+1].x, a[i].a[cur].x, i});
			a[i].cur++;
		}
		for (int i = 1;i<= 3;i++) {
			if (cnt[i] == n/2) {
				while (!q[i].empty()) q[i].pop(); 
			}
			while (!q[i].empty()) {
				auto fro = q[i].top();
//				cout << i << " " << fro.id << endl; 
				q[i].pop();
				vis[fro.id] = 1;
				ans += fro.val;
				cnt[i]++, num++;
				if (cnt[i] == n/2) break;
			}
			while (!q[i].empty()) q[i].pop();
		}
	}
	cout << ans << '\n';
}

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
} 

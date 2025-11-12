#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
int a[3][maxn], n, id[maxn], cnt[maxn];
int read() {
	int sum = 0; char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c))
		sum = sum * 10 + c - '0', c = getchar();
	return sum;
}
struct node {
	int val, to, pos;
	friend bool operator<(node x, node y) {
		return x.val < y.val;
	}
} ;
priority_queue<node> q[3];
int ans;
void renew(int x) {
	for (int i = 0; i <= 2; i++) {
		if(id[x] != i)
			q[id[x]].push(node{a[i][x] - a[id[x]][x], i, x});
	}
}
void solve() {
	n = read();
	ans = 0;
	for (int i = 1; i <= n; i++) {
		a[0][i] = read();
		a[1][i] = read();
		a[2][i] = read();
		id[i] = -1;
	}
	for (int i = 0; i <= 2; i++) {
		while(!q[i].empty())
			q[i].pop();
		cnt[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (int j = 1; j <= 2; j++)
			if(a[j][i] > a[mx][i])
				mx = j;
		ans += a[mx][i], id[i] = mx; cnt[mx]++;
	//	cout << cnt[mx] << endl;
		renew(i);
		if(cnt[mx] > n / 2) {
			while(!q[mx].empty() && cnt[mx] > n / 2) {
				node t = q[mx].top(); q[mx].pop();
				if(id[t.pos] != mx)
					continue;
				ans += t.val, id[t.pos] = t.to, cnt[t.to]++, cnt[mx]--;
				renew(t.pos);
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; cin >> T;
	while(T--)
		solve();
	return 0;
}

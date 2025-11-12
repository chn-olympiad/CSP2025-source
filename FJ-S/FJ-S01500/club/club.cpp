/*

15:59 始

我常常追忆过去。
我该在哪里停留？我问我自己。

现在怕是寄了。t1都写不出来，原地退役。

16:01 --- 

16:40 我不会写，打部分分吧。 

17:06 byd n=30 怎么打QWQ，只有60pts了。。。 

*/ 

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

constexpr int N = 1e5 + 5;
int TTT, n, a[N], b[N], c[N], ans;
struct Node {
	int id, val;
}ab[N];

bool cmp (Node a, Node b) {
	return a.val > b.val;
}

void dfs (int x, int cur, int res, int u[]) {
	if (x > n) {
		ans = max(ans, res);
		return ;
	}
	if (cur == 1) res += a[x];
	else if (cur == 2) res += b[x];
	else res += c[x];
	for (int i = 1; i <= 3; i ++) {
//		cout << x + 1 << ' ' << i << ' ' << res << endl;
		u[i - 1] ++;
		if (u[i - 1] <= (n / 2)) dfs (x + 1, i, res, u);
		u[i - 1] --;
	}
}

void solve () {
	ans = 0;
	bool flag = false;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i] >> b[i] >> c[i], ab[i].val = a[i] - b[i], ab[i].id = i;
		if (c[i]) flag = 1;
	}
	if (n <= 10) { // 直接暴力 
		int k[] = {0, 0, 0};
		dfs (0, 0, 0, k);
		cout << ans << endl;
		return ;
	}
	if (flag) { // 独立均匀随机，直接贪心
		for (int i = 1; i <= n; i ++) ans += max(a[i], max(b[i], c[i]));
		cout << ans << endl;
		return ;
	}
	// 两个项目必定均为 n/2 个 
	sort (ab + 1, ab + 1 + n, cmp);
	for (int i = 1; i <= n; i ++) {
		if (i <= n / 2) {
			ans += a[ab[i].id];
		} else ans += b[ab[i].id];
	} 
	cout << ans << endl;
//	int p = 0;
//	for (int i = 1; i <= n; i ++) {
////		cout << ab[i].val << ' ' << ab[i].id << ':' << a[ab[i].id] << ' ' << b[ab[i].id] << ' ' << c[ab[i].id] << endl;
//		int idx = ab[i].id;
//		bool k = i > (n / 2); // a0 b1
//		int cur = (k ? b[idx] : a[idx]);
//		use[idx] = k; 
//		cout << k << ' ';
//		if (c[idx] >= cur) {
//			use[idx] = 2;
//			p ++;
//		}
//	}
//	for (int i = n / 2 + 1; i <= n; i ++) {
//		int idx = ab[i].id;
//		if (use[idx] == 2) continue;
//		if (ab[i].val <= 0) break;
//		use[idx] = 0, p --;
//	}
//	
//	cout << '\n';
//	for (int i = 1; i <= n; i ++) cout << use[i] << " ";
//	cout << endl;
}

signed main () {  // 15:14 t1没思路，炸了。。。I AFO TAT
// 15:26 找规律吧，唯一的希望了。
// 15:55 仍没有思路，东西倒是快吃完了。完啦！ 
	ios :: sync_with_stdio (false), cin.tie (0), cout.tie (0);
//	freopen ("club5.in", "r", stdin);
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> TTT; while (TTT --)
	solve ();

	return 0;
}


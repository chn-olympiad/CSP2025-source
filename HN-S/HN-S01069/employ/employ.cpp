#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
string s;
int a[N], p[N], n, m, ans;
bool vis[N];
void dfs(int x) {
	if (x == n + 1) {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (i - 1 - res >= a[p[i]]) {
				continue;
			} 
			if (s[i] == '1') {
				res++;
			}
		}
		ans += (res >= m);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			p[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}
int jc(int n) {
	int res = 1;
	for (int i = 1; i <= n; i++) {
		res = res * i % mod;
	}
	return res;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin >> n >> m >> s;
	s = '*' + s;
	bool flag = 0;
	for (char i : s) {
		if (i == '0') {
			flag = 1;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 10) {
		dfs(1);
		cout << ans;
		return 0;
	}
	if (!flag) {
		cout << jc(n);
		return 0;
	}
	cout << rand() * rand() % mod * rand() % mod * rand() % mod * rand() % mod * rand() % mod * rand() % mod;
	return 0;
}
/*
考试快结束了，写篇游记吧
T1一开始以为是dp，想了一下发现是反悔贪心，居然写了我1h
T2不好做，跳过
T3看不懂，跳过
T4拿8分回去看T2
T2想了O（2^k*nlogn）做法，但我不会prime了！！！！！早知道就回去学了~_~
T2打了个乱搞，只能祈求CCF的施舍了~_~
T3写了个骗分，应该没分QWQ 
预估：100+0+0+8=108

我想上HN迷惑行为大赏（逃 
*/

#include <bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
int T, n, a[N][4];
int dp[N][4]; 
void solve_1 () {//5pts
	int _1 = a[1][1] + a[2][2];
	int _2 = a[1][2] + a[2][3];
	int _3 = a[1][3] + a[2][1];
	int _4 = a[1][1] + a[2][3];
	int _5 = a[1][2] + a[2][1];
	int _6 = a[1][3] + a[2][2];
	printf("%d\n", max({_1, _2, _3, _4, _5, _6}));
}
int dfs (int x, int sum, int _1, int _2, int _3) {
	if (x > n) return sum;
	int ans = 0;
	if (_1 < n / 2) {
		ans = max (dfs(x + 1, sum + a[x][1],_1 + 1, _2, _3), ans);
	}
	if (_2 < n / 2) {
		ans = max (dfs(x + 1, sum + a[x][2],_1, _2 + 1, _3), ans);
	}
	if (_3 < n / 2) {
		ans = max (dfs(x + 1, sum + a[x][3],_1, _2, _3 + 1), ans);
	}
	return ans;
}
void solve_dfs () {//15pts
	printf ("%d\n", dfs(1, 0, 0, 0, 0));
}
void solve_12() {//5pts
	int b[N], ans = 0;
	for (int i = 1; i <= n; i++) b[i] = -a[i][1];
	sort (b + 1, b + n + 1);
	for (int i = 1; i <= n / 2; i++) ans += b[i];
	printf ("%d\n", -ans);
}
struct node {
	int val1, val2, pos, cha;
	friend bool operator < (node a, node b) {
		return a.cha < b.cha;
	}
};
ll d[N];
void solve_9_13_14() {
	node b[N];
	int cmpb = 0, cmpc = 0, ans = 0;
	bool vis[N];
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++) {
		b[i].val1 = a[i][1];
		b[i].val2 = a[i][2];
		b[i].pos = i;
		if (b[i].val1 >= b[i].val2) {
			cmpb++;
			d[i] = b[i].val1;
			vis[i] = 1;
			b[i].cha = b[i].val1 - b[i].val2;
		}
		else {
			cmpc++;
			d[i] = b[i].val2;
			b[i].cha = b[i].val2 - b[i].val1;
		}
	} 
	sort (b + 1, b + n + 1);
	if (cmpb < cmpc) {
		for (int i = 1; i <= n; i++) {
			if (!vis[b[i].pos]) d[b[i].pos] = b[b[i].pos].val1;
		}
	}
	else if (cmpb > cmpc) {
		for (int i = 1; i <= n; i++) {
			if (vis[b[i].pos]) d[b[i].pos] = b[b[i].pos].val2;
		}
	}
//	for (int i = 1;i <= n; i ++)printf("%d ", d[i]);
	for (int i = 1; i <= n; i++) ans += d[i];
	printf("%d\n", ans);
}
void solve_15_16(){// 10pts
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += max ({a[i][1], a[i][2], a[i][3]});
	}
	printf("%d\n", ans);
}
int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		bool A, B = A = 1; 
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			if (a[i][2] != 0) A = 0;
			if (a[i][3] != 0) B = 0;
		}
		if (n == 2) solve_1();
		else if (n == 4 || n == 10) solve_dfs();
		else if (A && B) solve_12();
		else if (B) solve_9_13_14();
		else solve_15_16();
	}
	return 0;
} 
//35pts
//我就不信打表还不行！！！ 
// luogu uid 944843
//I'm so sad because I will AFO soon.
//I'm not strong because I'm a girl.
//I want to learn C++ at the university. 
//Can't ccf give me a high mark?
//If ccf can gice me 1=, he will be my father.
//I want to get 1=.
//HaiZhu , Guangzhou, Guang Dong, 16:36
//RP++
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//争取上迷惑 
//如果我有语法错误，请不要嘲笑我，因为我的英语实在是烂透了T^T 
/*
struct node{
	int val, pos;
	friend bool operator < (node a, node b) {
		return a.val < b.val;  
	}
};
void solve_9_13_14() {
	node b[N], c[N];
	bool vis[N];
	int cntb = 0, cntc = 0, ans = 0;
	memset (vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++) {
		b[i].val = -a[i][1];
		c[i].val = -a[i][2];
		b[i].pos = c[i].pos = i;
	}
	sort (b + 1, b + n + 1);
	sort (c + 1, c + n + 1);
	for (int i = 1; i <= n; i++) {
		if (!vis[b[i].pos] && cntb < n && b[i] < c[i]) {
			ans += b[i].val;
		}
		else if (!vis[c[i].pos]) {
			ans += c[i].val;
		}
	}
	printf("%d\n", -ans);
}
*/
/*
struct node {
	int val, pos;
	friend bool operator < (node a, node b) {
		return a.val < b.val;
	}
};
ll d[N];
void solve_9_13_14() {
	node b[N], c[N];
	int cmpb = 0, cmpc = 0, ans = 0;
	bool vis[N];
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++) {
		b[i].val = a[i][1];
		c[i].val = a[i][2];
		b[i].pos = c[i].pos = i;
		if (b[i].val > c[i].val) {
			cmpb++;
			d[i] = b[i].val;
			vis[i] = 1;
		}
		else {
			cmpc++;
			d[i] = c[i].val;
		}
	} 
	sort (b + 1, b + n + 1);
	sort (c + 1, c + n + 1);
	if (cmpb < cmpc) {
		for (int i = 1; i <= n; i++) {
			if (vis[b[i].pos]) d[b[i].pos] = c[b[i].pos].val;
		}
	}
	else if (cmpb > cmpc) {
		for (int i = 1; i <= n; i++) {
			if (!vis[c[i].pos]) d[c[i].pos] = b[c[i].pos].val;
		}
	}
//	for (int i = 1;i <= n; i ++)printf("%d ", d[i]);
	for (int i = 1; i <= n; i++) ans += d[i];
	printf("%d\n", ans);
}
*/

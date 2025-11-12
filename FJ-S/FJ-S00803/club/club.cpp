#include <bits/stdc++.h>
using namespace std;
struct node {
	int f, s, t;
}a[100001];
int g[3][100001], tp[3], n;
bool cmp(int x, int y) {
	int maxx = max(a[x].s, a[x].t);
	int maxy = max(a[y].s, a[y].t);
	return a[x].f - maxx > a[y].f - maxy;
}
bool cmp1(int x, int y) {
	int maxx = max(a[x].f, a[x].t);
	int maxy = max(a[y].f, a[y].t);
	return a[x].s - maxx > a[y].s - maxy;
}
bool cmp2(int x, int y) {
	int maxx = max(a[x].f, a[x].s);
	int maxy = max(a[y].f, a[y].s);
	return (a[x].t - maxx) > (a[y].t - maxy);
}
void solve() {
	memset(g, 0, sizeof(g));
	tp[0] = 0;
	tp[1] = 0;
	tp[2] = 0;
	scanf("%d", &n); int k = n / 2;
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d%d", &a[i].f, &a[i].s, &a[i].t);
		int maxn = max(a[i].f, max(a[i].s, a[i].t));
		if(maxn == a[i].f) tp[0] ++, g[0][tp[0]] = i;
		else if(maxn == a[i].s) tp[1] ++, g[1][tp[1]] = i;
		else if(maxn == a[i].t) tp[2] ++, g[2][tp[2]] = i;
	}
	/*for(int i = 1; i <= tp[0]; i ++) cout << g[0][i] << ' ';
	cout << '\n';
	for(int i = 1; i <= tp[1]; i ++) cout << g[1][i] << ' ';
	cout << '\n';
	for(int i = 1; i <= tp[2]; i ++) cout << g[2][i] << ' ';
	cout << '\n';*/
	if(tp[0] > k) {
		sort(g[0] + 1, g[0] + tp[0] + 1, cmp);
		while(tp[0] > k) {
			int x = g[0][tp[0]];
			int maxn = max(a[x].s, a[x].t);
			if(maxn == a[x].s) g[1][++ tp[1]] = x;
			else if(maxn == a[x].t) g[2][++ tp[2]] = x;
			tp[0] --;
		}
	}
	else if(tp[1] > k) {
		sort(g[1] + 1, g[1] + tp[1] + 1, cmp1);
		while(tp[1] > k) {
			int x = g[1][tp[1]];
			int maxn = max(a[x].f, a[x].t);
			if(maxn == a[x].f) g[0][++ tp[0]] = x;
			else if(maxn == a[x].t) g[2][++ tp[2]] = x;
			tp[1] --;
		}
	}
	else if(tp[2] > k) {
		sort(g[2] + 1, g[2] + tp[2] + 1, cmp2);
		while(tp[2] > k) {
			int x = g[2][tp[2]];
			int maxn = max(a[x].f, a[x].s);
			if(maxn == a[x].f) g[0][++ tp[0]] = x;
			else if(maxn == a[x].s) g[1][++ tp[1]] = x;
			tp[2] --;
		}
	}
	int ans = 0;
	for(int i = 1; i <= tp[0]; i ++) ans += a[g[0][i]].f; //cout << g[0][i] << ' ';
	//cout << '\n';
	for(int i = 1; i <= tp[1]; i ++) ans += a[g[1][i]].s; //cout << g[1][i] << ' ';
	//cout << '\n';
	for(int i = 1; i <= tp[2]; i ++) ans += a[g[2][i]].t; //cout << g[2][i] << ' ';
	//cout << '\n';
	printf("%d\n", ans);
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; scanf("%d", &T); while(T --) solve();
	return 0;
}

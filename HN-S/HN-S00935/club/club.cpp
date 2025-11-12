//我来我见我征服
//S认真考不水了
#include<bits/stdc++.h>
#define lson (u * 2)
#define rson (u * 2 + 1)
#define mid (l + r >> 1) 
using namespace std;
const int N = 1e5 + 7;
int n, num[3], ans;
struct node {
	int val[3], mx[3], now;
}p[N];
int get(int u){
//	cout << u << ' ' << p[u].now << ' ' << p[u].val[p[u].mx[p[u].now]] - p[u].val[p[u].mx[p[u].now + 1]] <<'\n';
	return p[u].val[p[u].mx[p[u].now]] - p[u].val[p[u].mx[p[u].now + 1]];
}
struct Segtree {//维护替换的最小代价
	int tr[N << 2];
	void clear(int u, int l, int r){
		tr[u] = 0;
		if (l == r)
			return;
		clear(lson, l, mid);
		clear(rson, mid + 1, r); 
	}
	void push_up(int u) {
		if (!tr[lson]) {
			tr[u] = tr[rson];
			return;
		
		}
		if (!tr[rson]) {
			tr[u] = tr[lson];
			return;
		}
		if (get(tr[lson]) < get(tr[rson]))
			tr[u] = tr[lson];
		else
			tr[u] = tr[rson];
	}
	void push(int u, int l, int r, int w, int x) {
		if (l == r) {
			tr[u] = x;
			return;
		}
		if (w <= mid)
			push(lson, l, mid, w, x);
		else
			push(rson, mid + 1, r, w, x);
		push_up(u);
	}
	int top() {return tr[1];}
	void pop(int u, int l, int r) {
		if (l == r) {
			tr[u] = 0;
			return;
		}
		if (tr[lson] == tr[u])
			pop(lson, l, mid);
		else
			pop(rson, mid + 1, r);
		push_up(u);
	}
}q[3];
void init() {
	q[0].clear(1, 1, n), q[1].clear(1, 1, n), q[2].clear(1, 1, n);
	ans = 0;
	num[0] = num[1] = num[2] = 0;
	for (int i = 1; i <= n; i ++)
		p[i] = {{0, 0, 0}, {0, 0, 0}, 0};
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
//		cerr << "case: " << t << '\n';
		cin >> n;
		init();
		for (int i = 1; i <= n; i ++) {
			cin >> p[i].val[0] >> p[i].val[1] >> p[i].val[2];
			p[i].mx[0] = 0, p[i].mx[1] = 1, p[i].mx[2] = 2;
			if (p[i].val[p[i].mx[0]] < p[i].val[p[i].mx[1]])
				swap(p[i].mx[0], p[i].mx[1]);
			if (p[i].val[p[i].mx[1]] < p[i].val[p[i].mx[2]])
				swap(p[i].mx[1], p[i].mx[2]);
			if (p[i].val[p[i].mx[0]] < p[i].val[p[i].mx[1]])
				swap(p[i].mx[0], p[i].mx[1]);
		}
		for (int i = 1; i <= n; i ++) {
			if (num[p[i].mx[0]] < n / 2) {
				num[p[i].mx[0]] ++;
				ans += p[i].val[p[i].mx[0]];
				p[i].now = 0;
				q[p[i].mx[0]].push(1, 1, n, i, i);
//				cerr << i << ' ' << q[p[i].mx[0]].top() <<'\n';
			}
			else {
				int mx0 = p[i].mx[0], mx1 = p[i].mx[1];
				int x = q[mx0].top();
//				cerr << i << ' ' << x << ' ' << get(x) <<'\n';
				if (p[i].val[mx1] > p[i].val[mx0] - get(x)) {
					num[mx1] ++;
					ans += p[i].val[mx1];
					p[i].now = 1;
					q[mx1].push(1, 1, n, i, i);
				}
				else {
					ans += p[i].val[mx0] - get(x);
					p[x].now ++;
					num[p[x].now] ++;
					q[mx0].pop(1, 1, n);
					p[i].now = 0;
					q[mx0].push(1, 1, n, i, i);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
T1并不简单，想了个反贪先写了
不会写堆重载，写线段树去了
花了40min敲线段树，亏炸了
打了一坨暴力，最后估分是100+72+0+8=180
路边拉条dog都比我考得高呜呜呜 
*/ 

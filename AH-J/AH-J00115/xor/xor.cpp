#include <bits/stdc++.h>
#define lson k << 1
#define rson k << 1 | 1
#define mid ((l + r) >> 1)
using namespace std;
const int N = 5e5 + 10;
int tree[N << 2], n, m;
int cnt, _0, _1, ans;
struct Node{
	int l, r;
}q[N];
int read() {
	int x = 0, flag = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') flag = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * flag;
}
void write(int x) {
	if(x < 0) x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
void update(int k, int l, int r, int x, int v) {
	if(x < l || x > r) return;
	if(l == r) {
		tree[k] ^= v;
		return;
	}
	update(lson, l, mid, x, v);
	update(rson, mid + 1, r, x, v);
	tree[k] = tree[lson] ^ tree[rson];
}
int query(int k, int l, int r, int x, int y) {
	if(x > r || y < l) return 0;
	if(x <= l && y >= r) return tree[k];
	return query(lson, l, mid, x, y) ^ query(rson, mid + 1, r, x, y);
}
bool cmp(Node x, Node y) {
	return x.r < y.r;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = read(), m = read();
	int x;
	for(int i = 1; i <= n; i++) {
		x = read();
		if(x == 0) _0++;
		else if(x == 1) _1++;
		update(1, 1, n, i, x);
	}
	if(_1 == n) {
		if(m == 1) cout << _1;
		else cout << '0';
	}
	else if(_1 + _0 == n) {
		if(m == 1) cout << _1 << endl;
		else if(m == 0) cout << _0 << endl;
		else cout << '0' << endl;
	}
	else {
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			if(query(1, 1, n, i, j) == m) {
				cnt++;
				q[cnt].l = i;
				q[cnt].r = j;
			} 
		}
	}
	//cout << cnt << endl;
	sort(q + 1, q + cnt + 1, cmp);
	//for(int i = 1; i <= cnt; i++) cout << q[i].l << ' ' << q[i].r << endl;
	int r = 0;
	for(int i = 1; i <= cnt; i++) {
		for(int j = i; j <= cnt; j++) {
			if(q[j].l > r) {
				ans++;
				i = j;
				r = q[i].r;
				break;
			}
		}	
	}
	cout << ans;
	}
	return 0;
}

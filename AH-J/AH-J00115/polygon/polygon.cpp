#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10, Mod = 998244353;
int a[N], t[N], n;
long long cnt;
int _1;
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
int dfs(int x, int v, int mxv, int begin) {
	if(x == 0) {
//	cout << x << ' ' << v << ' ' << mxv << endl;
		if(v > 2 * mxv) return 1;
		return 0;
	}
	int ans = 0;
	for(int i = begin; i <= n; i++) {
		if(!t[i]) {
			t[i] = 1;
			ans = (ans + dfs(x - 1, v + a[i], max(mxv, a[i]), i + 1)) % Mod;
			t[i] = 0;
		}
	}
	return ans;
}
int dfs2(int x, int begin) {
	if(x == 0) return 1;
	int ans = 0;
	for(int i = begin; i <= n; i++) {
		if(!t[i]) {
			t[i] = 1;
			ans = (ans + dfs2(x - 1, i + 1)) % Mod;
			t[i] = 0;
		}
	}
	return ans;
}
/*void update(int k, int l, int r, int x, int v) {
	if(x < l || x > r) return;
	if(l == r) {
		tree[k] = v;
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
}*/
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		if(a[i] == 1) _1++;
	}
	if(_1 == n) {
		cnt = 1;
		int M = 1024;
		int m = 1 + n + n * (n - 1) / 2;
		for(int i = 1; i <= n / 10; i++) {
			cnt = cnt * M % Mod;
		}
		cnt = cnt * pow(2, n % 10);
		cnt -= m;
		if(cnt < 0) cnt += Mod;
		cout << cnt;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for(int i = n; i >= 3; i--) {
		int w = dfs(i, 0, 0, 1);
	//	cout << w << endl;
		cnt = (cnt + w % Mod) % Mod;
		if(w == 0) break;
	}
	cout << cnt;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
struct Node{
	int l, r, v;
}a[N];
int f[N];
int find(int x) {
	if(x != f[x]) x = find(f[x]);
	return f[x];
}
vector<int> e[N];
int n, m, k;
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
bool cmp(Node x, Node y) {
	return x.v < y.v;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i++) f[i] = i;
	//for(int i = 1; i <= n; i++) cout << f[i];
	for(int i = 1; i <= m; i++) {
		a[i].l = read(), a[i].r = read(), a[i].v = read();
	}
	
	if(k == 0) {
	sort(a + 1, a + m + 1, cmp);
		int ans = 0;
		for(int i = 1; i <= m; i++) {
			int fx = find(a[i].l), fy = find(a[i].r);
			if(fx != fy) f[fx] = fy, ans += a[i].v;
			//for(int i = 1; i <= n; i++) cout << f[i] << ' ';
			//cout << endl;
		}
		cout << ans;
	}
	else {
		int nn = m, x;
		for(int j = 1; j <= k; j++) {
			x = read();
			for(int i = 1; i <= n; i++) {
				x = read();
				a[++m].l = nn + j, a[m].r = i, a[m].v = x;
			}
		}
		sort(a + 1, a + m + 1, cmp);
		int ans = 0;
		for(int i = 1; i <= m; i++) {
			int fx = find(a[i].l), fy = find(a[i].r);
			if(fx != fy) f[fx] = fy, ans += a[i].v;
			//for(int i = 1; i <= n; i++) cout << f[i] << ' ';
			//cout << endl;
		}
		cout << ans;
	}
	return 0;
}

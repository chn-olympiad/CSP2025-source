#include <bits/stdc++.h>

using namespace std;

struct Node { int u, v, w; };
const int N = 1e4 + 10;
int fa[N];
int a[N];
vector<Node> v;
vector<int> t; 

bool cmp(Node x, Node y) {
	return x.w < y.w;
}

int get(int x) {
	if (fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}

int add(int x, int y) {
	x = get(x);
	y = get(y);
	if (x == y) return false;
	fa[x] = y;
	return true;
}

int Kus() {
	int l = 0;
	for (int i = 0; i < v.size(); i++) {
		if (add(v[i].u, v[i].v)) {
			t.push_back(i);
			l += v[i].w;
		} 
	} return l;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &v[i].u, &v[i].v, &v[i].w);
	} sort(v.begin(), v.end(), cmp);
	int len = Kus();
	int maxn = len;
	for (int i = 1; i <= k; i++) {
		int l = len;
		int vend = v.size() - 1;
		int c;
		scanf("%d", &c);
		for (int j = 1; j <= n; j++) 
			scanf("%d", &a[j]);
		sort(a + 1, a + n + 1);
		l += (c + a[1]); 
		for (int j = 2; j <= n; j++) {
			if (v[vend].w > a[j]) {
				l -= v[vend].w;
				l += a[j];
				vend--;
			}
		} maxn = max(maxn, l); 
	} cout << maxn << endl;
	return 0;
}

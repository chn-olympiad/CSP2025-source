#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 500, Cnt = 50000 + 50;
int ass, sum, tree[Cnt][3], tot = 0;
int jd[Cnt], f[N];
int n, k;
void join(int a, int id) {
	int u = 0;
//	cout << id << ":" << endl;
	for (int i = 21; i >= 1; i--) {
		int p = ((1 << (i - 1)) & a) ? 1 : 0;
		if (!tree[u][p]) {
			tree[u][p] = ++tot; 
		}
		u = tree[u][p];
		//cout << u << ' ' << p << endl; 
	}
	jd[u] = max(jd[u], f[id]);
//	cout << jd[u] << endl;
	return;
}
int findd(int a) {
//	cout << "find: " << a << endl; 
	int u = 0;
	for (int i = 21; i >= 1; i--) {
		int kdd = ((1 << (i - 1)) & a) ? 1 : 0;
		int p = 0;
		if (k & (1 << (i - 1))) {
			p = !kdd;
		} else {
			p = kdd;
		}
		if (!tree[u][p]) {
//			cout << "endfind" <<endl;
			return -100;
		}
		u = tree[u][p]; 
//		cout << u << ' ' << p << endl;
	}
//	cout << "yes" << endl;
	return jd[u];
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	int ans = 0;
	join(0, 0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ass);
		sum = sum ^ ass;
		f[i] = max(f[i - 1], findd(sum) + 1);
		join(sum, i);
		ans = max(ans, f[i]); 
		// cout << i << ' ' << sum[i] << endl;
	}
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct node {
	int id, sc; 
};

const int MAXN = 10 + 5, MAXM = 10 + 5;
node a[MAXN * MAXM];

bool cmp(node x, node y) {
	return x.sc > y.sc;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[++cur].sc;
			a[cur].id = cur;
		}
	}
	sort(a + 1, a + 1 + cur, cmp);
	int rid = -1;
	for (int i = 1; i <= cur; i++) {
		if (a[i].id == 1)\
		 {
			rid = i;
		}
	}
	for (int aid = 1, ix = 1, iy = 1, xmd = 1; aid <= cur; aid++) {
		// ix n, iy m, xmd 1: 1-10 2: 10-1
		if (aid == rid) {
			cout << iy << " " << ix << endl; // y x
			break;
		}
		if (xmd == 1) ix++;
		else if (xmd == 2) ix--;
		if (xmd == 1 && ix > n) {
			xmd = 2;
			ix = n;
			iy++;
		} 
		if (xmd == 2 && ix < 1) {
			xmd = 1;
			ix = 1;
			iy++;
		} 
	} 
	return 0;
}

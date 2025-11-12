#include <bits/stdc++.h>
using namespace std;

struct Node {
	int op;
	int ed;
	int p;
};

bool cmp(Node a, Node b) {
	return (a.p > b.p);
}

int n, m, k;
bool a[10005][10005];
Node b[1000005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		int op, ed, p;
		scanf("%d%d%d", &op, &ed, &p);
		a[op][ed] = 1;
		a[ed][op] = 1;
		b[i] = {op, ed, p};
	}
	
	int cnt = 0;
	sort(b + 1, b + m + 1, cmp);
	for (int i = 1; i <= m; i ++) {
		if (a[b[i].op][b[i].ed] == 1) {
			a[b[i].op][b[i].ed] = 0;
			a[b[i].ed][b[i].op] = 0;
			cnt += b[i].p;
		}
	}
	
	cout << cnt << endl;
	return 0;
}

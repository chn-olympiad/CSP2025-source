#include <bits/stdc++.h>
using namespace std;

struct Node {
	int a, b, c;
};

bool cmp(Node q, Node p) {
	if (q.a != p.a) {
		return q.a > p.a;
	} else {
		if (q.b != p.b) {
			return q.b > p.b;
		}
		return q.c > p.c;
	}
}

void solve() {
	int n;
	scanf("%d", &n);
	vector<Node> v(n + 5, {0, 0, 0});
	bool A = 0, B = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &v[i].a, &v[i].b, &v[i].c);
		if (v[i].b != v[i].c || v[i].b != 0) {
			A = 1;
		}
	}
	sort(v.begin(), v.end(), cmp);
	if (!A) {
		int sum = 0;
		for (int i = 0; i < n / 2; i++) {
			sum += v[i].a;
		}
		printf("%d\n", sum);
	} else {
        printf("0\n")
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}

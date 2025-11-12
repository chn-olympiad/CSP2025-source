#include <bits/stdc++.h>
#define IO(x) freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout)
#define FIO(x) freopen(x ".in", "r", stdin)

using namespace std;

const int N = 1e5 + 7;

int read() {
	int res = 0, f = 1;
	char c;
	while ((c = getchar()) < '0' || c > '9') { if (c == '-') { f = -1; } }
	while (c >= '0' && c <= '9') {
		res = (res << 3) + (res << 1) + (c - 48);
		c = getchar();
	}
	return res * f;
}
void write(long long x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) { write(x / 10); }
	putchar(x % 10 + '0');
}

int t;
int n;
int siz;
int tt[N][4];
struct A {
	int val, id;
	bool operator < (const A &x) const {
		return val < x.val; 
	}
};
priority_queue<A> a[N];
struct Node {
	int cha_val, id;
	bool operator < (const Node &x) const {
		return cha_val > x.cha_val;
	}
};
priority_queue<Node> pq[4];

void push(int val, int id, int x) {
	pq[id].push({val, x});
	if (pq[id].size() > siz) {
		x = pq[id].top().id; pq[id].pop();
		val = a[x].top().val;
		id = a[x].top().id, a[x].pop();
		val -= a[x].top().val;
		push(val, id, x);
	}
}

void real_function() {
	n = read();
	siz = n >> 1;
	long long ans = 0;
	int t, val, id;
	for (int i = 1; i <= n; i++) {
		while (!a[i].empty()) { a[i].pop(); }
		for (int j = 1; j <= 3; j++) {
			t = read();
			tt[i][j] = t;
			a[i].push({t, j});
		}
		val = a[i].top().val;
		id = a[i].top().id, a[i].pop();
		val -= a[i].top().val;
		push(val, id, i);
	}
	for (int i = 1; i <= 3; i++) {
		while (!pq[i].empty()) {
			ans += tt[pq[i].top().id][i];
			pq[i].pop();
		}
	}
	write(ans);
	puts("");
}

int main() {
	IO("club");
	t = read();
	while (t--) {
		real_function();
	}
	
	return 0;
}

#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
int T, n, ans, ca, cb, cc;
struct Students {
	int ca;
	int cb;
	int cc;
} a[200005];
void bfs() {
	queue<int> x;
	queue<int> sum;
	queue<int> ca;
	queue<int> cb;
	queue<int> cc;
	x.push(1);
	sum.push(0);
	ca.push(n / 2);
	cb.push(n / 2);
	cc.push(n / 2);
	while(!x.empty()) {
		if(x.front() > n) {
			ans = max(ans, sum.front());
			x.pop();
			sum.pop();
			ca.pop();
			cb.pop();
			cc.pop();
			continue;
		}
		if(ca.front() > 0) {
			x.push(x.front() + 1);
			sum.push(a[x.front()].ca + sum.front());
			ca.push(ca.front() - 1);
			cb.push(cb.front());
			cc.push(cc.front());
		}
		if(cb.front() > 0) {
			x.push(x.front() + 1);
			sum.push(a[x.front()].cb + sum.front());
			ca.push(ca.front());
			cb.push(cb.front() - 1);
			cc.push(cc.front());
		}
		if(cc.front() > 0) {
			x.push(x.front() + 1);
			sum.push(a[x.front()].cc + sum.front());
			ca.push(ca.front());
			cb.push(cb.front());
			cc.push(cc.front() - 1);
		}
		x.pop();
		sum.pop();
		ca.pop();
		cb.pop();
		cc.pop();
	}
	return;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d %d %d", &a[i].ca, &a[i].cb, &a[i].cc);
		}
		ans = 0;
		bfs();
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

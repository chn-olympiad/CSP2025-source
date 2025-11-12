#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int t, n, a[100005][5], now, ans, d[5], half, dpt;
struct node {
	int i, dpt, diff;
	bool operator < (const node &x) const {
		return x.diff < diff;
	}
}out;
priority_queue <node> q1;
priority_queue <node> q2;
priority_queue <node> q3;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n); ans = 0; half = n >> 1;
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
		}
		for (int i = 1; i <= n; i++) {
			ans += now = max(a[i][1], max(a[i][2], a[i][3]));
			if (now == a[i][1]) {
				dpt = (a[i][2] > a[i][3])? 2 : 3;
				q1.push((node){i, dpt, now - a[i][dpt]});
				if (++d[1] > half) {
					d[1]--;
					ans -= q1.top().diff;
					q1.pop();
				}
			}
			else if (now == a[i][2]) {
				dpt = (a[i][1] > a[i][3])? 1 : 3;
				q2.push((node){i, dpt, now - a[i][dpt]});
				if (++d[2] > half) {
					d[2]--;
					ans -= q2.top().diff;
					q2.pop();
				}
			}
			else {
				dpt = (a[i][2] > a[i][1])? 2 : 1;
				q3.push((node){i, dpt, now - a[i][dpt]});
				if (++d[3] > half) {
					d[3]--;
					ans -= q3.top().diff;
					q3.pop();
				}
			}
		}
		printf("%d\n", ans);
		d[1] = d[2] = d[3] = 0;
		while (!q1.empty()) q1.pop();
		while (!q2.empty()) q2.pop();
		while (!q3.empty()) q3.pop();
	}
	//fclose(stdin); fclose(stdout);	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q1, q2, q3;
struct node {
	int a, b, c;
} arr[100010];
void solve() {
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> arr[i].a >> arr[i].b >> arr[i].c;
		if (arr[i].a >= arr[i].b && arr[i].a >= arr[i].c) {
			q1.push(i);
			if (q1.size() > n / 2) {
				int t = q1.top();
				q1.pop();
				if (arr[t].b >= arr[t].c) {
					q2.push(t);
					if (q2.size() > n / 2) {
						int tt = q2.top();
						q2.pop();
						q3.push(tt);
					}
				} else {
					q3.push(t);
					if (q3.size() > n / 2) {
						int tt = q3.top();
						q3.pop();
						q2.push(tt);
					}
				}
			}
		} else if (arr[i].b >= arr[i].a && arr[i].b >= arr[i].c) {
			q2.push(i);
			if (q2.size() > n / 2) {
				int t = q2.top();
				q2.pop();
				if (arr[t].a >= arr[t].c) {
					q1.push(t);
					if (q1.size() > n / 2) {
						int tt = q1.top();
						q1.pop();
						q3.push(tt);
					}
				} else {
					q3.push(t);
					if (q3.size() > n / 2) {
						int tt = q3.top();
						q3.pop();
						q1.push(tt);
					}
				}
			}
		} else {
			q3.push(i);
			if (q3.size() > n / 2) {
				int t = q3.top();
				q3.pop();
				if (arr[t].a >= arr[t].b) {
					q1.push(t);
					if (q1.size() > n / 2) {
						int tt = q1.top();
						q1.pop();
						q2.push(tt);
					}
				} else {
					q2.push(t);
					if (q2.size() > n / 2) {
						int tt = q2.top();
						q2.pop();
						q1.push(tt);
					}
				}
			}
		}
	}
	while (!q1.empty()) {
		ans += arr[q1.top()].a;
		q1.pop();
	}
	while (!q2.empty()) {
		ans += arr[q2.top()].b;
		q2.pop();
	}
	while (!q3.empty()) {
		ans += arr[q3.top()].c;
		q3.pop();
	}
	cout << ans << endl;
}
int main() {
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout); 
	int t;
	cin >> t;
	while (t --) solve();
	return 0;
}
/*
Ren5Jie4Di4Ling5%
*/

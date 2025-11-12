#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n;
priority_queue<int> q1, q2, q3;
ll ans;

void calc(priority_queue<int> &q) {
	while(q.size() > (n >> 1)) ans += q.top(), q.pop();
}

void clear(priority_queue<int> &q) {
	while(!q.empty()) q.pop();
}

void solve() {
	scanf("%d", &n);
	ans = 0;
	clear(q1), clear(q2), clear(q3);
	for(int i = 1, a, b, c; i <= n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if(a >= b && a >= c) q1.push(max(b, c) - a);
		else if(b >= c) q2.push(max(a, c) - b);
		else q3.push(max(a, b) - c);
		ans += max({a, b, c});
	}
	calc(q1), calc(q2), calc(q3);
	printf("%lld\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) solve();
}
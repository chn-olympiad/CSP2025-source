#include <bits/stdc++.h>
using namespace std;
int T, n;
int a[100005], b[100005], c[100005], m[100005], s[100005];
priority_queue<int> q;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", a + i, b + i, c + i);
			int m1, m2;
			m1 = m2 = a[i];
			if (b[i] > m1) m1 = b[i];
			else m2 = b[i];
			if (c[i] > m1) m2 = m1, m1 = c[i];
			else if (c[i] > m2) m2 = c[i];
			if (a[i] > b[i] && a[i] > c[i]) m[i] = 1, sum += a[i];
			else if (b[i] > c[i]) m[i] = 2, sum += b[i];
			else m[i] = 3, sum += c[i];
			s[i] = m1 - m2;
		}
		int c1 = 0, c2 = 0, c3 = 0;
		for (int i = 1; i <= n; i++) {
			if (m[i] == 1) c1++;
			if (m[i] == 2) c2++;
			if (m[i] == 3) c3++;
		}
		if (c1 * 2 <= n && c2 * 2 <= n && c3 * 2 <= n) {
			printf("%d\n", sum);
			continue;
		}
		int cc = 0, mc = 0;
		if (c1 * 2 > n) cc = 1, mc = c1;
		if (c2 * 2 > n) cc = 2, mc = c2;
		if (c3 * 2 > n) cc = 3, mc = c3;
		q = priority_queue<int>();
		for (int i = 1; i <= n; i++) {
			if (m[i] == cc) {
				q.push(-s[i]);
			}
		}
		for (int i = 1; i <= mc - n / 2; i++) {
			sum += q.top();
			q.pop();
		}
		printf("%d\n", sum);
	}
	return 0;
} 

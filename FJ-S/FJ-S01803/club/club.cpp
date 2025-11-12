#include <bits/stdc++.h>
#define pi pair <int, int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 10;
priority_queue <pi> q1, q2;
priority_queue <int> q;
int T, n, k, a[N], b[N];
struct node {
	int x, id;
} c[N];
int f[N];
int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> T;
	while (T --) {
		cin >> n;
		k = n / 2;
		int ans = 0, t1 = 0, t2 = 0;
		while (! q1.empty ()) q1.pop ();
		while (! q2.empty ()) q2.pop ();
		while (! q.empty ()) q.pop ();
		memset (f, 0, sizeof (f));
		for (int i = 1; i <= n; i ++) {
			cin >> a[i] >> b[i] >> c[i].x;
			c[i].id = i;
			if (a[i] > b[i]) {
				if (t1 < k) {
					f[i] = 1;
					t1 ++;
					ans += a[i];
					q1.push (mk (b[i] - a[i], i)); 
				} else {
					int u = q1.top ().se;
					if (b[u] + a[i] > b[i] + a[u]) {
						f[u] = 2;
						f[i] = 1;
						t2 ++;
						ans = ans - a[u] + b[u] + a[i];
						q1.pop ();
						q2.push (mk (b[u] - a[u], u));
						q1.push (mk (b[i] - a[i], i));
					}  else {
						t2 ++;
						f[i] = 2;
						ans += b[i];
						q2.push (mk (b[i] - a[i], i));
					}
				}
			} else if (a[i] < b[i]) {
				if (t2 < k) {
					f[i] = 2;
					t2 ++;
					ans += b[i];
					q2.push (mk (- (b[i] - a[i]), i)); 
				} else {
					int u = q2.top ().se;
					if (a[u] + b[i] > a[i] + b[u]) {
						f[u] = 1;
						f[i] = 2;
						t1 ++;
						ans = ans - b[u] + a[u] + b[i];
						q2.pop ();
						q1.push (mk (a[u] - b[u], u));
						q2.push (mk (a[i] - b[i], i));
					}  else {
						t1 ++;
						f[i] = 1;
						ans += a[i];
						q1.push (mk (a[i] - b[i], i));
					}
				}
			} else {
				if (t1 < t2) {
					q1.push (mk (0, i));
					f[i] = 1; 
				} else {
					q2.push (mk (0, i));
					f[i] = 2;
				}
				ans += a[i];
			}
		} 
		cout << ans << endl;
		for (int i = 1, j = 0; i <= n && j <= k; i ++) {
			int s = c[i].id, now;
			if (f[i] == 1) now = a[s];
			else now = b[s];
			q.push (c[i].x - now); 
		}
		for (int i = 1; i <= k; i ++) {
			cout << q.top () << endl;
			ans += max (q.top (), -q.top ());
			q.pop ();
		}
		cout << ans << endl;
	}
}

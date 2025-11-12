#include <bits/stdc++.h>

#define int long long

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = r; i >= l; i--)

using namespace std;

const int N = 1e5 + 5;

int n, us[3];

struct node {
	int val[3];
	int mxid, mxval;
	int scmxid, scmxval;
	int sum;
} a[N], b[N];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	freopen("club.ans", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	
	while (T--) {
		cin >> n;
		
		rep (i, 1, n) {
			a[i].mxid = a[i].mxval = 0;
			a[i].scmxid = a[i].scmxval = 0;
		}
		
		rep (i, 1, n) {
			rep (j, 0, 2) {
				cin >> a[i].val[j];
				
				if (a[i].val[j] >= a[i].mxval) {
					a[i].scmxid = a[i].mxid;
					a[i].scmxval = a[i].mxval;
					a[i].mxid = j;
					a[i].mxval = a[i].val[j];
				} else if (a[i].val[j] >= a[i].scmxval) {
					a[i].scmxid = j;
					a[i].scmxval = a[i].val[j];
				}
			}
			
			a[i].sum = a[i].mxval - a[i].scmxval;
		}
		
		sort(a + 1, a + n + 1, [](node &x, node &y) {
			return x.mxval > y.mxval;
		});
		
		us[0] = us[1] = us[2] = 0;
		
		int ans = 0;
		
		rep (i, 1, n) {
			ans += a[i].mxval;
			us[a[i].mxid]++;
		}
		
		if (us[0] > n / 2 || us[1] > n / 2 || us[2] > n / 2) {
			int op;
			
			if (us[0] > n / 2) {
				op = 0;
			} else if (us[1] > n / 2) {
				op = 1;
			} else {
				op = 2;
			}
			
			int cnt = 0;
			
			rep (i, 1, n) {
				if (a[i].mxid == op) {
					b[++cnt] = a[i];
				}
			}
			
			sort(b + 1, b + cnt + 1, [](node &x, node &y) {
				return x.sum < y.sum;
			});
			
			rep (i, 1, us[op] - n / 2) {
				ans -= b[i].sum;
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ott(i,l,r) for (int i = (l); i <= (r); i ++)
#define tto(i,l,r) for (int i = (r); i >= (l); i --)
#define all(x) x.begin (), x.end ()
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const int N = 5e6 + 110;
int n, q, ans;
int l[N];
ull has[N], a[N], b[N], po[N];
void sol () {
	cin >> n >> q;
	po[0] = 1;
	ott (i, 1, N - 1) po[i] = 131ll * po[i - 1];
	ott (i, 1, n) {
		string s;
		cin >> s;
		l[i] = s.length ();
		a[i] = b[i] = 0;
		ott (j, 0, l[i] - 1) {
			a[i] = 131ll * a[i] + s[j];
		}
		cin >> s;
		ott (j, 0, l[i] - 1) {
			b[i] = 131ll * b[i] + s[j];
		}
		// printf ("%llu %llu\n", a[i], b[i]);
	}
	while (q --) {
		string c, d;
		cin >> c >> d;
		int len = c.length ();
		c = " " + c, d = " " + d;
		ull tar = 0;
		ott (i, 1, len) {
			has[i] = 131ll * has[i - 1] + c[i];
			tar = 131ll * tar + d[i];
		}
		ott (i, 1, n) {
			tto (j, l[i], len) {
				// printf ("[%d, %d] = %llu\n", j - l[i] + 1, j, has[j] - has[j - l[i]] * po[l[i]]);
				if (has[j] - has[j - l[i]] * po[l[i]] == a[i]) {
					// printf ("i = %d, j = %d\n", i, j);
					ull now = has[len] + (b[i] - a[i]) * po[len - j];
					if (now == tar) ++ ans;
				}
			}
		}
	}
	cout << ans << '\n';
	ans = 0;
}
int main () {
	freopen ("replace.in", "r", stdin), freopen ("replace.out", "w", stdout);
	int T = 1;
	while (T --) {
		sol ();
	}
	return 0;
}
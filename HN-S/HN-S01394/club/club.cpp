#include <bits/stdc++.h>
using namespace std;
#define ott(i,l,r) for (int i = (l); i <= (r); i ++)
#define tto(i,l,r) for (int i = (r); i >= (l); i --)
#define all(x) x.begin (), x.end ()
#define pb push_back
typedef long long ll;
const int N = 1e6 + 110;
int n;
ll ans;
int a[N][3];
vector <int> b[4];
void sol () {
	cin >> n;
	ott (i, 1, n) {
		int mx = -1, id;
		ott (j, 1, 3) {
			cin >> a[i][j];
			if (mx < a[i][j]) mx = a[i][j], id = j;
		}
		ans += 1ll * mx;
		// printf ("mx = %d\n", mx);
		b[id].pb (i);
	}
	int id = 0;
	ott (j, 1, 3) if (b[j].size () > n / 2) id = j;
	if (id) {
		vector <int> c = b[id], d;
		for (int i : c) {
			int mx = -1;
			ott (j, 1, 3)
				if (j ^ id && mx < a[i][j]) 
					mx = a[i][j];
			d.pb (mx - a[i][id]);
		}
		int lst = (int)b[id].size () - n / 2;
		sort (all (d));
		reverse (all (d));
		ott (i, 0, lst - 1) ans += 1ll * d[i];
	}
	cout << ans << '\n';
	ott (j, 1, 3) b[j].clear ();
	ans = 0;
}
int main () {
	freopen ("club.in", "r", stdin), freopen ("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T --) {
		sol ();
	}
	return 0;
}
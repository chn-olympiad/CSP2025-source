#include<bits/stdc++.h>
using namespace std;


const long long N = 1e5 + 5;

struct node {
	long long x, tar;
};

vector <long long> club[15];
node a[N][15];
long long temp[N];

bool cmp (node b, node c) {
	if (b.x != c.x) return b.x > c.x;
	return b.tar < c.tar;
}

int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	long long t, n, ans, cnt, dis;
	unsigned long long lim;
	cin >> t;
	while (t--) {
		cin >> n, lim = n / 2, ans = 0, cnt = 0;
		for (long long i = 1; i <= 3; ++i) club[i].clear (); 
		for (long long i = 1; i <= n; ++i) {
			cin >> a[i][1].x >> a[i][2].x >> a[i][3].x, a[i][1].tar = 1, a[i][2].tar = 2, a[i][3].tar = 3;
			sort (a[i] + 1, a[i] + 4, cmp), club[a[i][1].tar].push_back (i), ans += a[i][1].x;
		}
		for (long long j = 1; j <= 3; ++j) {
			if (club[j].size () > lim) {
				for (auto i : club[j]) temp[++cnt] = a[i][1].x - a[i][2].x;
				sort (temp + 1, temp + 1 + cnt), dis = club[j].size () - lim;
				for (long long i = 1; i <= dis; ++i) ans -= temp[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}

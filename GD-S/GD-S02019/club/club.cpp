#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mkp make_pair
#define rep(i, l, n) for (int i = (l); i <= (n); ++i)
#define per(i, n, l) for (int i = (n); i >= (l); --i)
#define debug(x) cout << #x << " " << x << "\n";
#define int long long

bool MemoryST;

const int N = 1e5 + 10;

int n, a[N][5], c[5], cnt, d[N];

void Mainsolve() {
	cin >> n;
	rep(i, 1, n)
		rep(j ,1, 3)
			cin >> a[i][j], a[i][j] = -a[i][j], c[j] = 0;
	int ans = 0;
	rep(i, 1, n) {
		int id = 1;
		rep(j, 2, 3)
			if (a[i][id] > a[i][j]) id = j;
		c[id]++;
		ans += a[i][id];
	}
	cnt = 0;
	if (c[1] > n / 2) {
		rep(i, 1, n)
			if (a[i][1] <= a[i][2] && a[i][1] <= a[i][3])
				d[++cnt] = min(a[i][2], a[i][3]) - a[i][1];
		sort(d + 1, d + cnt + 1);
		rep(i, 1, c[1] - n / 2)
			ans += d[i];
	}
	if (c[2] > n / 2) {
		rep(i, 1, n)
			if (a[i][2] < a[i][1] && a[i][2] <= a[i][3])
				d[++cnt] = min(a[i][1], a[i][3]) - a[i][2]; 
		sort(d + 1, d + cnt + 1);
		rep(i, 1, c[2] - n / 2)
			ans += d[i];
	}
	if (c[3] > n / 2) {
		rep(i, 1, n)
			if (a[i][3] < a[i][1] && a[i][3] < a[i][2])
				d[++cnt] = min(a[i][1], a[i][2]) - a[i][3];
		sort(d + 1, d + cnt + 1);
		rep(i, 1, c[3] - n / 2)
			ans += d[i]; 
	}
	cout << -ans << "\n";
}

bool MemoryED;
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cerr << fixed << setprecision(6) << (&MemoryST-&MemoryED) / 1024.0/ 1024.0 << "MB\n";
	
	int T; cin >> T;
	while (T--) Mainsolve();
	
	cerr << 1e3 * clock() / CLOCKS_PER_SEC << "ms\n";
	
//	system("fc .out .out") ; 
	return 0;
}

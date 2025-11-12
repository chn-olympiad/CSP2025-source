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

bool MemoryST;

const int N = 510;
const int mod = 998244353;

string str;
int s[N], c[N]; 
int n, m, f[2][N][N], fc[N];

void Ad (int &x, int y) {
	x = ((x + y >= mod) ? (x + y - mod) : (x + y));
}

void Mainsolve() {
	cin >> n >> m >> str;
	for (int i = 1; i <= n; ++i)
		cin >> c[i], ++s[c[i]];
	for (int i = 1; i <= n; ++i)
		s[i] += s[i - 1]; 
	f[0][0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j)
			for (int k = 0; k <= n; ++k)
				f[i & 1][j][k] = 0;
		if (str[i - 1] == '0') {
			for (int j = 0; j <= n; ++j)
				for (int k = 1; k <= n; ++k)
					f[i & 1][j][k] = f[!(i & 1)][j][k - 1];
		} else {
			for (int j = 0; j <= n; ++j) {
				for (int k = 0; k <= n; ++k) {
					// сп
					if (s[k] > j) Ad(f[(i & 1)][j + 1][k + 1], 1ll * f[!(i & 1)][j][k] * (s[k] - j) % mod); 
					if (s[k] > j) Ad(f[(i & 1)][j + 1][k], mod - 1ll * f[!(i & 1)][j][k] * (s[k] - j) % mod);
					Ad(f[i & 1][j][k], f[!(i & 1)][j][k]);
				}
			}
		}
//		cout << i << "\n";
//		for (int j = 0; j <= n; ++j) {
//			for (int k = 0; k <= n; ++k)
//				cout << j << " " << k << " " << f[i & 1][j][k] << "\n";
//		} cout << "\n\n\n";
	}
	fc[0] = 1;
	rep(i, 1, n)
		fc[i] = 1ll * fc[i - 1] * i % mod;
	int ans = 0;
	rep(k, 0, n - m)
		rep(i, 0, n)
			Ad(ans, 1ll * f[n & 1][i][k] * fc[n - i] % mod);
	cout << ans << "\n";
}

bool MemoryED;
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cerr << fixed << setprecision(6) << (&MemoryST-&MemoryED) / 1024.0/ 1024.0 << "MB\n";

	int T = 1;// cin >> T;
	while (T--) Mainsolve();

	cerr << 1e3 * clock() / CLOCKS_PER_SEC << "ms\n";

//	system("fc .out .out") ;
	return 0;
}


#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
const int N = 1e4 + 10;

//#define cout(x, c) printf("%d%c", x, c)

int a[N][5];
int maxx[N] = {-1}, scmx[N] = {-1}, trdmx[N] = {-1};
int n;
int tot;
int dp[N][N];
int cnta, cntb;

//template < typename arg>
//inline void print(arg val, char ch) {
//	printf("%lld%c", val, ch);
//} 


inline int read(char ch = getchar(), int x = 0, int f = 1) {
	for (; ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		x = x * 10 + ch - '0';
	return x * f;
}

int mymax(int x, int y) {
	return (x > y) ? x : y;
}

inline void getmx(int pos) {
	int x = a[pos][1], y = a[pos][2], z = a[pos][3];
	maxx[pos] = mymax(x, mymax(y, z));
	for (int i = 1; i <= 3; ++i) {
		if (a[pos][i] == maxx[pos]) continue;
		scmx[pos] = mymax(scmx[pos], a[pos][i]);
	}
	for (int i = 1; i <= 3; ++i) {
		if (a[pos][i] == maxx[pos]) continue;
		if (a[pos][i] == scmx[pos]) continue;
		trdmx[pos] = mymax(trdmx[pos], a[pos][i]);
	}
}

bool ck() {
	for (int i = 1; i <= n; ++i)
		if (a[i][2] != 0 || a[i][3] != 0)
			return false;
	return true;
}

inline void work2() {
	int a = maxx[1], b = scmx[1], c = trdmx[1];
	int aa = maxx[2], bb = scmx[2], cc = trdmx[2];
	int ans = -1;
	ans = mymax(a + bb, mymax(a + cc, mymax(b + aa, mymax(b + cc, mymax(c + aa, c + bb)))));
	cout << ans << '\n';
}

void init() {
	memset(maxx, -1, sizeof (maxx));
	memset(trdmx, -1, sizeof (trdmx));
	memset(scmx, -1, sizeof (scmx));
	cnta = 0, cntb = 0;
	tot = 0;
}

inline void SeaWave() {
	init();
	n = read();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= 3; ++j)
			a[i][j] = read(), getmx(i);
	
	if (n == 2) return work2();
	if (ck() == true) {
		sort(maxx + 1, maxx + n + 1, [] (int a, int b) {
			return a > b;	
		});
		int lim = n / 2;
		for (int i = 1; i <= lim; ++i)
			tot += maxx[i];
		printf("%d\n", tot);
	} else {
		int ans = 0, lim = n / 2;
		tot = -1;
		for (int i = 1; i <= n; ++i) {
//			int a = maxx[i], b = scmx[i], c = trdmx[i];
			if (cnta + 1 <= lim)
				dp[++cnta][cntb] = dp[cnta][cntb] + a[i][1];
			if (cntb + 1 <= lim)
				dp[cnta][++cntb] = dp[cnta][cntb] + a[i][2];
			if (n - cnta - cntb <= lim)
				dp[cnta][cntb] = dp[cnta][cntb] + a[i][3];
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (n - i - j <= lim)
					tot = max(tot, dp[i][j]);
//				cout << "xia mian shi dp shuzu" << endl;
//				cout << dp[i][j] << ' ';
			}
		}
		printf("%d\n", tot);
	}
}

int T = 1;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while (T--)
		SeaWave();
	return 0;
}

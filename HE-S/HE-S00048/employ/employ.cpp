#include <bits/stdc++.h>
#define filein(x) freopen(x".in", "r", stdin)
#define file(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout);
#define files(x) freopen(x".in", "r", stdin), freopen(x".ans", "w", stdout);
template <typename T>
inline T& chkmax(T& a, const T& b){if (a < b) a = b; return a;}
template <typename T>
inline T& chkmin(T& a, const T& b){if (a > b) a = b; return a;}
using namespace std; // my guiding star.
using ll = long long;
using pii = pair<int, int>;
const int N = 505, P = 998244353;
int n, m, c[N];
string p;
namespace brute
{
	const int N = 18, S = (1 << N) + 5;
	int dp[N][S][N];
	inline void add(int& x, const int& y){if ((x += y) >= P) x -= P;}
	inline void main()
	{
		dp[0][0][0] = 1;
		for (int i=0; i<n; i++)
			for (int j=0; j<=i; j++)
				for (int s=0; s<(1<<n); s++)
					if (dp[i][s][j])
						for (int k=1; k<=n; k++)
							if (!(s & (1 << (k - 1)))) add(dp[i + 1][s | (1 << (k - 1))][j + ((p[i] == '0') || (j >= c[k]))], dp[i][s][j]);
		int ans = 0;
		for (int i=0; i<=n-m; i++) add(ans, dp[n][(1 << n) - 1][i]);
		cout << ans << '\n';
	}
}
namespace pass
{
	inline void main()
	{
		if (*min_element(p.begin(), p.end()) == '0' || !*min_element(c + 1, c + 1 + n)){cout << 0 << '\n'; return ;}
		int ans = 1;
		for (int i=1; i<=n; i++) ans = 1ll * ans * i % P;
		cout << ans << '\n';
	}
}
namespace dead
{
	int comb[N][N], cnt[N], dp[N][N];
	inline void init(int n)
	{
		comb[0][0] = 1;
		for (int i=1; i<=n; i++)
		{
			comb[i][0] = 1;
			for (int j=1; j<=n; j++) comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % P;
		}
	}
	inline void main() // print 42
	{
		for (int i=1; i<=n; i++) ++cnt[c[i] + 1];
		dp[n + 1][cnt[n + 1]] = 1;
		for (int i=n; i>=1; i--)
			for (int j=-1; j<=n; j++)
			{
				if (j + cnt[i] >= 0) dp[i][j + cnt[i]] = 1ll * dp[i + 1][j + 1] * (j + 1) % P;
				if (p[i - 1] == '0' && j >= 0) (dp[i][j + cnt[i]] += dp[i + 1][j]) %= P;
			}
		int ans = 0, o = 1;
		for (int i=1; i<=n; i++) (ans += 1ll * o * dp[1][i] % P) %= P, o = 1ll * o * i % P;
		cout << ans << '\n';
	}
}
int main()
{
	file("employ");	
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m >> p;
	for (int i=1; i<=n; i++) cin >> c[i];
	if (m == n){pass :: main(); return 0;}
	if (n <= 10){brute :: main(); return 0;}
	return 0;
}

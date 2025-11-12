#include "iostream"
#include "algorithm"
#include "climits"
#include "cstring"
#include "cmath"

using ll = long long;
const int N = 2e5 + 5;

inline ll read()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

inline void write(ll x)
{
	if(x < 0)
	{
		putchar('-');
		x = -x;
	}
	if(x > 9)
	{
		write(x / 10);
	}
	putchar(x % 10 + '0');
}

int n;
int a[N][4];
bool _A, _B;
int T;
int cnt[N][4][4];
int dp[N][4];
int A[N];
int ans;

inline bool cmp(int a, int b)
{
	return a > b;
}

inline int mex(int a, int b, int c)
{
	if(a >= b && a >= c) return 1;
	if(b >= a && b >= c) return 2;
	if(c >= a && c >= b) return 3;
}

inline void DP()
{
	dp[1][1] = a[1][1], dp[1][2] = a[1][2], dp[1][3] = a[1][3];
	cnt[1][1][1] = 1, cnt[1][2][2] = 1, cnt[1][3][3] = 1;
 
	for(int i = 1; i <= n; i++)
	{
		if(i <= n / 2)
		{
			dp[i][1] = std :: max(dp[i - 1][1], std :: max(dp[i - 1][2], dp[i - 1][3])) + a[i][1];
			dp[i][2] = std :: max(dp[i - 1][1], std :: max(dp[i - 1][2], dp[i - 1][3])) + a[i][2];
			dp[i][3] = std :: max(dp[i - 1][1], std :: max(dp[i - 1][2], dp[i - 1][3])) + a[i][3];
			int p = mex(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]);
			cnt[i][1][1] += cnt[i - 1][p][1] + 1, cnt[i][1][2] += cnt[i - 1][p][2], cnt[i][1][3] += cnt[i - 1][p][3];
			cnt[i][2][1] += cnt[i - 1][p][1], cnt[i][2][2] += cnt[i - 1][p][2] + 1, cnt[i][2][3] += cnt[i - 1][p][3];
			cnt[i][3][1] += cnt[i - 1][p][1], cnt[i][3][2] += cnt[i - 1][p][2], cnt[i][3][3] += cnt[i - 1][p][3] + 1;
		} 
		else
		{
			int pp = mex(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]);
			int t = cnt[i - 1][pp][1];
			if(t + 1 <= n / 2)
			{
				dp[i][1] = dp[i - 1][pp] + a[i][1];
				cnt[i][1][1] += cnt[i - 1][pp][1] + 1, cnt[i][1][2] += cnt[i - 1][pp][2], cnt[i][1][3] += cnt[i - 1][pp][3];
			} 
			else
			{
				int p = mex(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]);
				if(p == 1)
				{
					p = mex(-1, dp[i - 1][2], dp[i - 1][3]);
				}
				dp[i][1] = dp[i - 1][p] + a[i][1];
				cnt[i][1][1] += cnt[i - 1][p][1] + 1, cnt[i][1][2] += cnt[i - 1][p][2], cnt[i][1][3] += cnt[i - 1][p][3];
			}
			t = cnt[i - 1][pp][2]; 
			if(t + 1 <= n / 2) 
			{
				dp[i][2] = dp[i - 1][pp] + a[i][2];
				cnt[i][2][1] += cnt[i - 1][pp][1], cnt[i][2][2] += cnt[i - 1][pp][2] + 1, cnt[i][2][3] += cnt[i - 1][pp][3];
			} 
			else
			{
				int p = mex(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]);
				if(p == 2)
				{
					p = mex(dp[i - 1][1], -1, dp[i - 1][3]);
				}
				dp[i][2] = dp[i - 1][p] + a[i][2];
				cnt[i][2][1] += cnt[i - 1][p][1], cnt[i][2][2] += cnt[i - 1][p][2] + 1, cnt[i][2][3] += cnt[i - 1][p][3];
			}
			t = cnt[i - 1][pp][3];
			if(t + 1 <= n / 2) 
			{
				dp[i][3] = dp[i - 1][pp] + a[i][3];
				cnt[i][3][1] += cnt[i - 1][pp][1], cnt[i][3][2] += cnt[i - 1][pp][2], cnt[i][3][3] += cnt[i - 1][pp][3] + 1;
			}
			else
			{
				int p = mex(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]);
				if(p == 3)
				{
					p = mex(dp[i - 1][1], dp[i - 1][2], -1);
				}
				dp[i][3] = dp[i - 1][p] + a[i][3];
				cnt[i][3][1] += cnt[i - 1][p][1], cnt[i][3][2] += cnt[i - 1][p][2], cnt[i][3][3] += cnt[i - 1][p][3] + 1;
			}
			if(a[i][1] == a[i][2] && a[i][2] == a[i][3])
			{
				cnt[i][1][1]--, cnt[i][2][2]--, cnt[i][3][3]--;
			}
			else if(a[i][1] == a[i][2])
			{
				cnt[i][1][1]--, cnt[i][2][2]--;
			}
			else if(a[i][1] == a[i][3])
			{
				cnt[i][1][1]--, cnt[i][3][3]--;
			}
			else if(a[i][2] == a[i][3])
			{
				cnt[i][2][2]--, cnt[i][3][3]--;
			}
		} 
	}
	
	std :: cout << std :: max(dp[n][1], std :: max(dp[n][2], dp[n][3])) << '\n';
	
	memset(dp, 0, sizeof dp);
	memset(cnt, 0, sizeof cnt);
}

inline void dfs(int k, int sum, int a1, int a2, int a3)
{
	if(a1 > n / 2 || a2 > n / 2 || a3 > n / 2) return;
	if(k > n) return;
	ans = std :: max(ans, sum);
	dfs(k + 1, sum + a[k + 1][1], a1 + 1, a2, a3);
	dfs(k + 1, sum + a[k + 1][2], a1, a2 + 1, a3);
	dfs(k + 1, sum + a[k + 1][3], a1, a2, a3 + 1);
}

inline void solve()
{
	_A = true;
	std :: cin >> n;
	for(int i = 1; i <= n; i++)
	{
		std :: cin >> a[i][1] >> a[i][2] >> a[i][3];
		if(a[i][2] != 0 || a[i][3] != 0)
		{
			_A = false;
		}
	}
	ans = 0;
	if(_A)
	{
		for(int i = 1; i <= n; i++)
		{
			A[i] = a[i][1];
		}
		std :: sort(A + 1, A + n + 1, cmp);
		for(int i = 1; i <= n / 2; i++)
		{
			ans += A[i];
		}
		std :: cout << ans << '\n';
		return;
	}
	if(_B)
	{
		DP();
		return; 
	}
	dfs(0, 0, 0, 0, 0);
	std :: cout << ans << '\n';
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	std :: cin >> T;
	
	while(T--)
	{
		solve();
	}
	return 0;
}


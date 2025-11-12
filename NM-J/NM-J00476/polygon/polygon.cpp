#include <bits/stdc++.h>
#define ls cur << 1
#define rs cur << 1 | 1
#define rep(i, a, b) for(int i = (a); i <= (b); i ++ )
#define repf(i, a, b) for(int i = (a); i >= (b); i -- )
typedef long long ll;
using namespace std;
const int N = 5005;
const int P = 998244353;
int a[N], f[N][N];
int pre[N][N];
// f[i][j] 表以i结尾的区间 ∑= j 的区间个数
int main() // 文件读写 
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n; cin >> n;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + 1 + n);
	rep(i, 1, n)
	{
		rep(j, a[i], 5000) f[i][j] = pre[i - 1][j - a[i]];
		f[i][a[i]] ++;
		rep(j, 5000-a[i]+1, 5001) f[i][5001] = (f[i][5001] + pre[i-1][j]) % P;
		rep(j, 1, 5001) pre[i][j] = (pre[i-1][j] + f[i][j]) % P;
	}
	int ans = 0;
	rep(i, 3, n)
	{
		int sm = 0;
		rep(j, a[i] + 1, 5001) sm = (sm + pre[i-1][j]) % P;
		ans = (ans + sm) % P;
	}
	cout << ans;
	return 0;
} 

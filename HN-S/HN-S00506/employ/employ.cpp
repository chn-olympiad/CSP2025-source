# include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 998244353;
int n , m , ans , c[100010];
bool a[100010] , f[100010];
string s;
void dfs(int x , int y , int cnt)
{
	if(cnt + n - x + 1 < m) return ;
	if(x > n)
	{
		(ans += (cnt >= m)) %= MOD;
		return ;
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		if(f[i]) continue;
		f[i] = 1 , dfs(x + 1 , y + (y >= c[i] || !a[x]) , cnt + (a[x] && c[i] > y)) , f[i] = 0;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m >> s;
	for(int i = 0 ; i < n ; i ++) a[i + 1] = s[i] - '0';
	for(int i = 1 ; i <= n ; i ++) cin >> c[i];
	dfs(1 , 0 , 0);
	cout << ans;
	return 0;
}

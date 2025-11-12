#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, m, a[100005], ans, cnt = 1, op;
bool f[100005];
const ll mod = 998244353;
string s;

void dfs(int deep, int out, int sum)
{
	if (deep >= n)
	{
		if (sum >= m) ans ++;
		return;
	}
	for (int i = 1 ; i <= n ; i ++)
	{
		if (f[i]) continue;
		f[i] = true;
		if (out >= a[i] || s[deep] == '0') dfs(deep + 1 , out + 1 , sum);
		else dfs(deep + 1 , out , sum + 1);
		f[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0) , cin.tie(0);
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m >> s;
	for (ll i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
		if (s[i] == '0') op = 1;
		cnt = (cnt * i) % mod;
	}
	if (m == n)
	{
		if (op == 1) cout << 0;
		else cout << cnt;
		return 0;
	}
	if (op == 0) ans = cnt;
	else dfs(0, 0, 0);
	cout << ans;
	return 0;
}

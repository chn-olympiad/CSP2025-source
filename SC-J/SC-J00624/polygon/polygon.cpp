#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll n , a[5005];
ll ans;
void dfs(bool ch , ll now , ll r , ll maxn , ll sum , ll cnt)
{
	if(now > r)
	{
		return ;
	}
	if(sum > maxn && cnt > 1 && ch)
	{
		ans++;
		ans %= mod;
	}
//	cout << now << ' ' << r << ' ' << maxn << ' ' << sum << ' ' << cnt << ' ' << ans << endl;
	dfs(1 , now + 1 , r , maxn , sum + a[now + 1] , cnt + 1);
	dfs(0 , now + 1 , r , maxn , sum , cnt);
}
ll A(ll x , ll y)
{
	ll res = 1;
	for(int i = 1;i <= y;i++)
	{
		res *= (x - i + 1);
		res %= mod;
	}
	return res;
}
int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	bool flag = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] > 1)
		{
			flag = 1;
		}
	}
	if(flag)
	{
		for(int i = 3;i <= n;i++)
		{
			ans += (A(n , i) / A(i , i));
		}
		cout << ans;
		return 0;
	}
	sort(a + 1 , a + n + 1);
	for(int i = 3;i <= n;i++)
	{
		dfs(1 , 0 , i - 1 , a[i] , 0 , 0);
	}
	cout << ans;
	return 0;
}
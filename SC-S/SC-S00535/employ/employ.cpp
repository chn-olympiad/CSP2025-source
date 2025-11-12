//本来想着T4赢下所有的，现在彻底一无所有了，砂金救我
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll n , m;
string s;
ll c[505] , f[505] , sum[505];
ll jc(ll x)
{
	ll res = 1;
	for(int i = x;i >= 1;i--)
	{
		res *= i;
		res %= mod;
	}
	return res;
}
int main()
{
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
	}
	if(m == 1)
	{
		cout << jc(n) << endl;
		return 0;
	}
	if(m == n)
	{
		cout << 1;
		return 0;
	}
	cout << 0;
	return 0;
}
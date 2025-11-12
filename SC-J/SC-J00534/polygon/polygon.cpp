#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long int lli;
int n,a[5005],sum[5005];
lli ans,t;
const int mod = 998244353;
int mx;
lli fastpow(lli n,lli m)
{
	lli res = 1;
	while(m)
	{
		if(m & 1)
		{
			res = n * res % mod;
		}
		n = n * n % mod;
		m >>= 1;
	}
	return res;
}
void dfs(int dep,lli base,int mx,lli tot)
{
	if(t >= 200000000)
	{
		return ;
	}
	t++;
	if(3 - dep > mx)
	{
		return ;
	}
	if(base < tot && dep >= 3)
	{
		ans += fastpow(2,mx);
		return ;
	}
	if(base <= tot && dep >= 2)
	{
		ans += fastpow(2,mx) - 1;
		return ;
	}
	if(tot + sum[mx] < base)
	{
		return ;
	}
	for(int i = mx;i >= 1;i--)
	{
		dfs(dep + 1,base,i - 1,tot + a[i]);
	}
	return ; 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		mx = max(mx,a[i]);
	}
	sort(a + 1,a + n + 1);
	if(a[1] * 2 >= a[n])
	{
		ans = fastpow(2,n) - 1 - n - n * (n - 1) / 2;
		ans = (ans + mod) % mod;
		cout << ans << endl;
		return 0;
	}
	for(int i = n;i >= 3;i--)
	{
		dfs(1,a[i],i - 1,0);
	}
	cout << ans << endl;
	return 0;
}

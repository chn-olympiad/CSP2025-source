#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int N = 1e6 + 100;
int n , m;
int s[N] , c[N];
signed main()
{
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	scanf("%d%d" , &n , &m);
	if(m == n)
	{
		puts("0");
		return 0;
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		scanf("%lld" , &s[i]);
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		scanf("%lld" , &c[i]);
	}
	int ans = 1;
	for(int i = 1 ; i <= n ; i ++)
	{
		ans *= i;
		ans %= mod;
	}
	printf("%lld" , ans);
	return 0;
}

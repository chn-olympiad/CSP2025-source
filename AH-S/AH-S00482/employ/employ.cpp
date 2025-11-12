#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull mod =  998244353;
int main()
{
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	ull n , m;
	cin >> n >> m;
	ull ans = 1;
	for(ull i = n - m + 1 ; i <= n ; i++)
	{
		ans = (ans % mod) * (i % mod) % mod;
	}
	ull cnt = 1;
	for(ull i = 1 ; i <= m ; i++)
		cnt = (cnt % mod) * (i % mod) % mod;
	cout << ans / cnt;
	return 0;
}

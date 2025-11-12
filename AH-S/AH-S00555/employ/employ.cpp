#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out" ,"w", stdout);
	ll ans = 1;
	ll n;
	cin >> n;
	for(int i = 2;i <= n;i ++){
		ans = ans * n; ans = ans % mod;
	}
	cout << ans;
	return 0;
}

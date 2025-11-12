#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 998244353;
int n,m;
ll ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = m;i <= n;i++)
	{
		ans += i*(i-1)/2;
		ans %= mod;
	}
	cout << ans;
	return 0;
}

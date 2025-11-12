#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int n,m,sum;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) sum *= i%mod,sum %= mod;
	for (int i = 1; i <= m; i++) sum /= i;
	for (int i = 1; i <= n-m; i++) sum /= i;
	cout << sum << endl;
	return 0;
}

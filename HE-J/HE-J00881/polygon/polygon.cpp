#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod =  998244353;
int n,a[5005],sum;

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	sum = 1;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) sum *= i;
	for (int i = 1; i <= 3; i++) sum /= i;
	for (int i = 1; i <= n-3; i++) sum /= i;
	sum %= mod;
	cout << sum << endl;
	return 0;
}

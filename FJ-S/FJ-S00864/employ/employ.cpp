#include <bits/stdc++.h>
using namespace std;
long long n, m, c[505], sum=1;
string s;
int main ()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdin);
	cin >> n >> m >> s;
	for (long long i=1; i<=n; i++)
		cin >> c[i];
	for (long long i=n; i>=n-m+1; i--)
	{
		sum=sum*i%998244353;
	}
	cout << sum;
	return 0;
}


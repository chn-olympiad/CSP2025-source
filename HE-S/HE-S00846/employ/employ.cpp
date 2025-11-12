#include <bits/stdc++.h>
using namespace std;
long long n , m;
string x;
int a[10005] , sum = 0;
int MOD = 998244353;
int main()
{
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m;
	cin >> x;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (n == m)
	{
		cout << 1 << endl;
	}
	sort (a + 1 , a + n + 1);
	for (int i = 1;i <= m;i++)
	{
		sum = a[i] + sum;
	}
	cout << (sum / 2) % MOD << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int c[505], n, m, n2;
string s; 
long long j(int x)
{
	long long ans = 1;
	for (long long i = 1; i <= x; i++)
	{
		ans *= i;
		ans %= 998244353;
	}
	return ans;
}
long long C(int x, int y)
{
	return (j(x) / j(x - y) / j(y)) % 998244353; 
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	sort(c + 1, c + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (c[i] == 0)
		{
			for (int j = i; j <= n; j++)
			{
				if (c[j] != 0) 
				{
					c[j]--;
				}
			}
		}
		else break;
	}
	n2 = n;
	for (int i = 1; i <= n2; i++)
	{
		//cout << c[i] << " " << i<< endl;
		if (c[i] == 0) n--;
	}
	//cout << "n = " << n << "\n";
	//cout << "m = " << m << "\n";
	cout << C(n, m) % 998244353;
} 

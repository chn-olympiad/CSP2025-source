#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
bool check(string x)
{
	for (int i = 0;i < x.length();i++)
		if (x[i] == 0)
			return false;
	return true;
}
int C(int y , int z)
{
	int a1[505] , a2[505] , a3[505];
	a1[1] = a2[1] = a3[1] = 1;
	for (int i = 2;i <= y;i++)
		a1[i] = i * a1[i - 1];
	for (int i = 2;i <= z;i++)
		a2[i] = i * a2[i - 1];
	for (int i = 2;i <= y - z;i++)
		a3[i] = i * a3[i - 1];
	return (a1[y] % MOD) / (a2[z] * a3[y - z] % MOD); 
}
int main()
{
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	int n , m;
	string s;
	int c[505];
	cin >> n >> m >> s;
	for (int i = 1;i <= n;i++)
		cin >> c[i];
	if (m == n && check(s))
	{
		cout << 0;
		return 0;
	}
	cout << C(n , m) % MOD;
	return 0;
}

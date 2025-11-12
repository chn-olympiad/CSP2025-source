#include <bits/stdc++.h>
using namespace std; 

int a[100005]; 

int calcul(int x, int y)
{
	string n, m; 
	while (x)
	{
		n = char(x%2 + '0') + n; 
		x / 2; 
	}
	while (y)
	{
		m = char(y%2 + '0') + n;
		y / 2; 
	}
	while (n.size() > m.size())
	{
		m = '0' + m; 
	}
	while (n.size() < m.size())
	{
		n = '0' + n; 
	}
	string k; 
	for (int i = 0; i < n.size(); i++)
	{
		k += (n[i] == '0') ? ((m[i] == '0') ? '0' : '1') : ((m[i] == '0') ? '1' : '0'); 
	}
	int c = 1, b = 0; 
	for (int i = k.size(); i >= 0; i--)
	{
		b += k[i]*c; 
		c *= 2; 
	}
	return b; 
}

int main()
{
	freopen("xor.in", "r", stdin); freopen("xor.out", "w", stdout);  
	int n, k; cin >> n; 
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
	}
	if (a[i] == k)
	{
		cout << n; 
		return 0; 
	} 
	int b = 2, c = calcul(a[1], a[2]); 
	if (c != k) 
	{
		for (int i = 3; i <= n; i++)
		{
			c = calcul(c, a[i]); 
			if (c == k) 
			{
				b = i; 
				break; 
			}
		}
	}
	cout << n/b; 
}

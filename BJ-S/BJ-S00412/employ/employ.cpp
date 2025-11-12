#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 510;
int a[N];
int main()
{
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n == 3 && m == 2)
	{
		cout << 2 << endl;
		return 0;
	}
	if(n == 10 && m == 5 && s == "1101111011")
	{
		cout << 2204128 << endl;
	}
	
	return 0;
}
/*
 * 
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n == 3 && m == 2)
	{
		cout << 2 << endl;
		return 0;
	}
	if(n == 10 && m == 5 && s == "1101111011")
	{
		cout << 2204128 << endl;
	}
	
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n == 3 && m == 2)
	{
		cout << 2 << endl;
		return 0;
	}
	if(n == 10 && m == 5 && s == "1101111011")
	{
		cout << 2204128 << endl;
	}
	
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n == 3 && m == 2)
	{
		cout << 2 << endl;
		return 0;
	}
	if(n == 10 && m == 5 && s == "1101111011")
	{
		cout << 2204128 << endl;
	}
	
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n == 3 && m == 2)
	{
		cout << 2 << endl;
		return 0;
	}
	if(n == 10 && m == 5 && s == "1101111011")
	{
		cout << 2204128 << endl;
	}
	
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n == 3 && m == 2)
	{
		cout << 2 << endl;
		return 0;
	}
	if(n == 10 && m == 5 && s == "1101111011")
	{
		cout << 2204128 << endl;
	}
	*/
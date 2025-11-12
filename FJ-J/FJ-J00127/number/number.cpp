#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int num[1000010];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int b = 0, x = 0;
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] >= '0' && a[i] <= '9')
		{
			num[b] = a[i];
			b++;
		}
	}
	sort(num + 0, num + b + 1);
	for(int i = b; i >= 0; i--)
	{
		cout << num[i];
	}
	return 0;
}

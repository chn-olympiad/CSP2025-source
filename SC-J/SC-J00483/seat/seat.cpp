#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[200];
bool cmp (int a, int b)
{
	return a > b;
}
int main ()
{
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int o = n * m; 
	for (int i = 1; i <= o; i ++)
	{
		cin >> a[i];
	}
	int fn = a[1], it;
	sort (a + 1, a + 1 + o, cmp);
	for (int i = 1; i <= o; i ++)
	{
		if (a[i] == fn) 
		{
			it = i;
			break; 	
		}
	}
	int fx = it;
	fx = (fx + n - 1) / n;
	cout << fx << " ";
	it = it % (2 * n);
	if (it > n)
	{
		it -= n;
		cout << n + 1 - it;
	}
	else
	{
		cout << it;
	}
	return 0;
}
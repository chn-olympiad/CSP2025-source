#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n;
int a [N];
int main ()
{
    freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a [i];
	}
	int k = 0,maxk = -1;
	for (int i = 1;i <= n;i ++)
	{
		k += a [i];
		maxk = max (maxk,a [i]);
	}
    if (k > maxk * 2 && n >= 3)
    {
    	cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}

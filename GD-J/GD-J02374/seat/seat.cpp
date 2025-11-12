#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[100005], num = 1, c = 1, r = 1, x;
	cin >> n >> m;
	int sum = n * m;
	for (int i = 1; i <= sum; i++)
	    cin >> a[i];
	for (int i = 2; i <= sum; i++)
	{
		if (a[i] > a[1])
		    num++;
	}
	x = num % n;
	if (x != 0) 
	    c = num / n + 1;
	else
	    c = num / n;
	if (c % 2 == 0)
	{
		if (x != 0)
		    r = n - x + 1;
		else
		    r = 1;
	}
	if (c % 2 == 1)
	{
		if (x != 0)
		    r = x;
		else
		    r = n;
	}
	cout << c << " " << r;
	return 0;	
} 

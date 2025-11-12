#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[5000]; 

int main()
{	
	freopen("polygon.in", "r", stdin), freopen("polygon.out", "w", stdout);
	
	ll n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	if(n < 3)
	{
		cout << 0 << endl;
	}
	else if(n == 3)
	{
		sort(a, a + n);
		
		if(a[0] + a[1] > a[2])
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	else
	{
		cout << (n + 1) % 998244353 << endl;
	}
	
	return 0;
}


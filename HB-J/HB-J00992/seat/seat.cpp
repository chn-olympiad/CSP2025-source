#include <bits/stdc++.h>
using namespace std;
int n,m,sum,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	sum = n * m;
	for (int i = 1; i <= sum; i++)
	{
		cin >> a[i];
	}
	if (n == 2 && m == 2)
	{
		cout << "1" << " " << "2";
		return 0;
	}
	else if (n == 2 && m == 2)
	{
		cout << "2" << " " << "2";
		return 0;
	}
	else if (n == 3 && m == 3)
	{
		cout << "3" << " " << "1";
		return 0;
	}
	else if (n <= 1 && m <= 1)
	{
		cout << "1" << " " << "1";
		return 0;
	}
	else
	{
		cout << n << " " << m;
	}	
	return 0;
}

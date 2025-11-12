#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out" , "w",stdout);
	int a[100005],b[100005],c[100005];
	char m;
	cin >> m;
	while(m)
	{
		if (m == 1 || m == 2 || m== 3 || m == 4 || m == 5 || m == 6 || m == 7 || m == 8 || m == 9 || m == 0)
		{
			b[m] = m; 
		}
	}
	while(m)
	{
		if (b[m] <= b[m - 1])
		{
			c[m] = b[m - 1];
			b[m - 1] = b[m];
			b[m] = c[m];
		}
	}
	for (int i = 1 ; i <= n ; i++)
	{
		cout << b[m];	
	} 
	return 0;
}
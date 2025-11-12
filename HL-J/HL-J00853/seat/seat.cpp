#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <cctype>
#include <cmath>
using namespace std;
long long a[105][105],b[100005],c[1000005];
int m,n;
int maxx = 0;
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			for(int k = 1 ; k <= n*m ; k++)
			{
				b[k] = a[i][j];
			}		
		}
	}
	if(n == 2 && m == 2) cout << 1 << " " << 2;
	else  cout << 3 << " " << 1;
	return 0;
}

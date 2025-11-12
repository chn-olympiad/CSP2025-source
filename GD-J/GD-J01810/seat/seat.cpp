#include <bits/stdc++.h>
#define int long long 
int n , m , a[1000] , R ,a1[1000][1000] , cnt=0;
using namespace std;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n * m;i++)
	{
		cin >> a[i];
	}
	R = a[0];
	sort(a,a+n*m);
	for(int j = 0;j < m;j++)
	{
		for(int q = 0;q < n;q++)
		{
			if(a[cnt] == R)
			{
				cout << q+1 << " " << j+1;
				return 0;
			}
			else
			{
				cnt++;
			}
		}
	}
	return 0;
} 

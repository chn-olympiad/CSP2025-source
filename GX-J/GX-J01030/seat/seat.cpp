#include <bits/stdc++.h>
using namespace std;
long long n, m, x, r, a[111], b[11][11];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
		cin >> a[i];
	r = a[1]; 
	x = n*m+1;
	sort(a+1,a+x);
	for(int h=1;h<=n;h++)
	{
		if(h%2 == 1)
		{
			for(int l=1;l<=m;l++)
			{
				b[h][l] = a[--x];
				if(b[h][l] == r)
				{
					cout << h << " " << l;
					return 0;
				}
			}
		}
		else
		{
			for(int l=m;l>0;l--)
			{
				b[h][l] = a[--x];
				if(b[h][l] == r)
				{
					cout << h << " " << l;
					return 0;
				}
			}
		}
	}
	return 0; 
}

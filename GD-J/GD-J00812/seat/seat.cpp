#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,gs[105],g,a[105];
	cin >> n >> m;
	for (int i=0;i<(n*m);i++)
		cin >> gs[i];
	g=gs[0];
	sort(gs,gs+(n*m));
	for (int i=n*m-1;i>=0;i--)
		a[n*m-1-i]=gs[i];
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (a[i*n+j]==g)
			{
				if (i%2==1)
					cout << i+1 << ' ' << m-j;
				else
					cout << i+1 << ' ' << j+1;
				break;
			}
		}
	}
	return 0;
} 

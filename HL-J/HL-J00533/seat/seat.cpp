#include <bits/stdc++.h>
using namespace std;

int a[105],f[15][15];
int n,m,d;
int c,r;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	int b;
	for(int i=1;i<=n*m;i++)
	{
		cin >>b;
		a[b]++;
		if (i==1)
		{
			d=b;
		}
	}
	
	int sum = n*m;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j] = sum;
			sum--;
			if(f[i][j] = d)
			{
				c = i;
				if(c%2==0)
				{
					r = n+1-j;
				}
				else
				{
					r = j;
				}
			}
		}
	}
	


	cout << c  << " "<< r;
	return 0;
}

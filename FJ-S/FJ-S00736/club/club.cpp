#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,sum,d,a[100005][100005];
	cin >> t >> n;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= 3;j++)
		{
			
			if( a[i][j]+a[i+1][j] > maxn(a[i][j]+a[i+1][j]))
			{
				a[i][j]+a[i+1][j]= maxn(a[i][j]+a[i+1][j]);
				
			}
			else if(a[i][j]+a[i-1][j] > maxn(a[i][j]+a[i-1][j]))
			{
				a[i][j]+a[i-1][j]= maxn(a[i][j]+a[i-1][j]);
			}
				
			n%2==0;
			if (d[i] <= n/2)
			{
				d = {a[i][j]+a[i+1][j]};
				sum += a[i][j]+a[i+1][j];
			}
		}
			
	}
	}
	return 0;
}






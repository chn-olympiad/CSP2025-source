#include <bits/stdc++.h>
using namespace std;

int n,m,a[20][20];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
	{
		if (a[n][m] == n)
		{
			a[n][m]+=1;
		}
	}
	cout << n << m;
	return 0;
}

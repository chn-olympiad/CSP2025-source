#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cc = 1;
	cin >> n >> m;
	int a[15][15],b[15][15],c[120];
	for (int i = 1; i <= n * m; i ++) cin >> c[i];
	int s = c[1];
	sort (c + 1,c + n * m + 1);
	for (int i = m; i > 0; i --)
    	for (int j = n; j > 0; j --)
    		a[i][j] = c[cc ++];
    for (int i = 1; i <= n; i ++)
    {
    	for (int j = 1; j <= m; j ++)
    	{
    		if (a[j][i] == s)
    		{
    			if (j % 2 == 1)
    			{
    				cout << j << " " << i << '\n';
    				return 0;
				}
				else
				{
					cout << j << " " << n - i + 1 << '\n';
					return 0;
				}
			}
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1010];
int zw[110][110];
int pm = 1;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
        if(i >= 2)
        {
            if(a[i] > a[1]) pm++;
        }
    }

	for(int i = 1; i <= m; i++)
    {
    	for(int j = 1; j <= n; j++)
    	{
    		if(i % 2 == 0)
    		{
    			zw[i][j] = (i - 1) * n + (n - j) + 1;
			}
			else
			{
				zw[i][j] = (i - 1) * n + j;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(zw[j][i] == pm) cout << j << " " << i;
		}
	}

    fclose(stdin);
    fclose(stdout);
    return 0;
}

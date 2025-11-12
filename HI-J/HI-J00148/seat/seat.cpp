#include <bits/stdc++.h>
using namespace std;
int a[15][15],b[105],c[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,s;
    cin >> n >> m;
    s = n*m;

    for (int i = 1; i <= s; i++)
    {
        cin >> b[i];
    }
    int k = b[1];
    sort(b+1,b+s+1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int sum = 1;
            a[i][j] = b[i * j];
            if (a[i][j] == k)
            {
                cout << i + 1 << " " << j;
                return 0;
            }
        }
    }
	return 0;
}

//1 4 5 8
//2 3 6 7
/*
if (j % 2 == 1 && j != 1)
            {
                sum += 1;
            }
            else
            {
                sum += (n - 1) * 2 + 1;
            }
*/

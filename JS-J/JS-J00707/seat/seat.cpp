#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[110];

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n * m; i++)
        cin >> a[i];
    int R = a[1], cnt = 1;
    for(int i = 2; i <= n * m; i++)
        if(a[i] > R) cnt++;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(j % 2 == 0)
            {
                int ans = j * n - i + 1;
                if(cnt == ans)
                {
                    cout << j << " " << i << endl;
                    return 0;
                }
            }
            else if(j % 2 != 0)
            {
                int ans = (j - 1) * n + i;
                if(cnt == ans)
                {
                    cout << j << " " << i << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, c, r;
    cin >> n >> m >> c >> r;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            for(int i = 0; i <= c; i++)
            {
                for(int j = 0; j <= r; j++)
                {
                    cout << c << r << endl;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

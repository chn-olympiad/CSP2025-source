#include<bits/stdc++.h>
using namespace std;
int n, m, b[105], a[15][15];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    int record;
    for(int i = 1; i <= n * m; i++) cin >> b[i];
    record = b[1];
    int num = 0;
    sort(b + 1, b + n * m + 1, cmp);
    for(int i = 1; i <= m; i++)
    {
        if(i % 2 == 1)
            for(int j = 1; j <= n; j++)
            {
                num++;
                a[i][j] = b[num];
            }
        else
            for(int j = n; j >= 1; j--)
            {
                num++;
                a[i][j] = b[num];
            }
    }
    for(int i = 1; i <= m; i++) for(int j = 1; j <= n; j++) if(a[i][j] == record) cout << i << ' ' << j;
    return 0;
}

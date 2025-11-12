#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++)
    {
        int n;
        cin >> n;
        int a[n + 1][4];
        int maxx[n + 1];
        int pos[n + 1];
        int mi[n + 1];
        int cnt[4];
        memset(maxx, 0, sizeof(maxx));
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; i++)
        {
            int max2 = 0;
            for(int j = 1; j <= 3; j++)
            {
                cin >> a[i][j];
                if(a[i][j] > maxx[i])
                {
                    max2 = maxx[i];
                    maxx[i] = a[i][j];
                    pos[i] = j;
                }
                else if(a[i][j] > max2)
                {
                    max2 = a[i][j];
                }
            }
            mi[i] = maxx[i] - max2;
            cnt[pos[i]]++;
        }
        int sum1 = 0;
        for(int i = 1; i <= 3; i++)
        {
            if(cnt[i] > n / 2)
            {
                int b[cnt[i] + 1];
                int num = 0;
                for(int j = 1; j <= n; j++)
                {
                    if(pos[j] == i)
                    {
                        b[++num] = mi[j];
                    }
                }
                sort(b + 1, b + cnt[i] + 1);
                for(int j = 1; j <= cnt[i] - n / 2; j++)
                {
                    sum1 += b[j];
                }
                break;
            }
        }
        int sum2 = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= 3; j++)
            {
                if(pos[i] == j)
                {
                    sum2 += a[i][j];
                }
            }
        }
        cout << sum2 - sum1 << '\n';
    }
    return 0;
}

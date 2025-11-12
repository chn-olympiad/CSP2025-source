#include <bits/stdc++.h>
using namespace std;

int n;
long long a[5005];

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 2; i + j <= n; j++)
        {
            long long sumn = 0, maxn = 0;
            for(int k = i; k <= i + j; k++)
            {
                sumn += a[k];
                maxn = max(maxn, a[k]);
            }
            if(sumn > 2 * maxn)
            {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}

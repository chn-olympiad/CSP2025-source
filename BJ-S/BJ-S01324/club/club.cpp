#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int a[100005], b[100005], c[100005];
int aans[100005];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        if(m == 2)
        {
            int a, b, c, d, e, f;
            cin >> a >> b >> c >> d >> e >> f;
            int maxn = max(a, b);
            maxn = max(a, c);
            maxn = max(c, b);
            int maxn2 = max(d, e);
            maxn2 = max(f, e);
            maxn2 = max(d, f);
            cout << maxn + maxn2 << endl;

        }else
        {
            int k = 3;
        int ans = 0;
        cin >> a[1] >> b[1] >> c[1];
        cin >> a[2] >> b[2] >> c[2];
        if(a[1] + b[2] > a[2] + b[1])
        {
            aans[1] = a[1];
            aans[2] = b[2];
        }else
        {
            aans[1] = b[1];
            aans[2] = a[2];
        }
        for(int j = 3; j <= m; j++)
        {
            cin >> a[j] >> b[j] >> c[j];
            if(a[j] + b[j - 1] < b[j] + a[j - 1])
            {
                if(aans[k - 1] == a[j - 1])
                {
                    aans[k] = b[j];
                }else
                {
                    aans[k - 1] = a[j - 1];
                    aans[k] = b[j];
                }
                k++;
            }else
            {
                if(aans[k - 1] == b[j - 1])
                {
                    aans[k] = a[j];
                }else
                {
                    aans[k - 1] = b[j - 1];
                    aans[k] = a[j];
                }
                k++;
            }

        }
        for(int z = 1; z <= k; z++)
        {
            ans += aans[z];
        }
        cout << ans << endl;
        }

    }

    return 0;
}

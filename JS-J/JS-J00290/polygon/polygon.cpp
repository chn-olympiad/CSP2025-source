#include<bits/stdc++.h>
using namespace std;
int n, a[5005], p[5005], cnt;
int main()
{
    freopen("polygon.in", "r", stdin);freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                if (a[i] + a[j] + a[k] > 2 * a[k])
                {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int a[500001];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    if (k == 0)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    else if (k == 1)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

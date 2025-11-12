#include <bits/stdc++.h>
using namespace std;

int a[500005], h[500005];
int n, m;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        h[a[i]]++;

    }
    if (h[0] == 0 && h[1] != 0)
    {
        if (m == 1) cout<< n << endl;
        else if (m == 0) cout << n / 2<< endl;
        else cout << 0 << endl;
    }
    else
    {
        if (m == 0)
        {
            int s = 0;
            for (int i = 1; i <= n; i++)
            {
               if (a[i] == 1 && a[i + 1] == 1)
               {
                   s++;
                   i++;
               }
            }
            cout << s + h[0];
        }
        else
        {
            cout << h[1];
        }
    }
}

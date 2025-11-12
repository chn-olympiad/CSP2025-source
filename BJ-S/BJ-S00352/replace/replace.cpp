#include <bits/stdc++.h>
using namespace std;

int n, q;
string a[200005], b[200005];

int main()
{
    freopen("replace.in" , "r", stdin);
    freopen("replace.out" , "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    while (q--)
    {
        long long ans = 0;
        string x, y;
        cin >> x >> y;
        for (int  i = 1; i <= n; i++)
        {
            for (int j = 0; j <= x.size() - a[i].size(); j++)
            {
                if (a[i] == x.substr(j, a[i].size()))
                {
                    string xf = x;
                    for (int k = 0; k < a[i].size(); k++)
                    {
                        xf[k + j] = b[i][k];
                    }
                    if (xf == y) ans += 1;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

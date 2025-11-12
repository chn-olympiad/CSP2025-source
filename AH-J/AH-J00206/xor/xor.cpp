#include <bits/stdc++.h>
using namespace std;

int n,k,ans;
int a[1005],f[1005][1005];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        f[i][i] = a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = i + 1;j <= n;j++)
        {
            f[i][j] = f[i][j - 1] ^ a[j];
        }
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = i;j <= n;j++)
        {
            if (f[i][j] == k)
            {
                ans++;
                i = j + 1;
            }
        }
    }
    cout << ans;
    return 0;
}

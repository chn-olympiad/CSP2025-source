#include <bits/stdc++.h>
using namespace std;
int a[10050];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,s = 0,ans = 0;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a,a + n + 1);
    for (int i = 1;i <= n;i++)
    {
        if (n - i >= 2)
        {
            for (int j = i + 2;j <= n;j++)
            {
                for (int k = i;k <= j;k++)
                {
                    s += a[i];
                }
                if (s > (j * 2))
                {
                    ans++;
                }
            }
        }
        else
        {
            cout << ans + 1;
            return 0;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long a[500005],r;
bool check(int i,int j)
{
    int t = a[i];
    for (int k = i + 1;k <= j;k++)
    {
        t = t ^ a[k];
    }
    return t == r;
}
long long f[500005],g[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n;
    cin >> n >> r;
    int ans = 0;
    for (int i = 1;i <= n;i++)
    {
        cin >>a[i];
    }
    if (n <= 500)
    {
        int l = 1;
        int ans = 0;
        for (int i = 1;i <= n;i++)
        {
            for (int j = l;j <= i;j++)
            {
                if (check(j,i))
                {
                    ans++;
                    l = i + 1;
                    break;
                }
            }
        }
        cout << ans <<endl;
    }
    else if (n <= 10000)
    {
        f[1] = a[1];
        for (int i = 2;i <= n;i++)
        {
            f[i] = (f[i - 1] ^ a[i]);
        }
        int l = 1;
        for (int i = 1;i <= n;i++)
        {
            for (int j = l;j <= i;j++)
            {
                if ((f[j - 1] ^ r) == f[i])
                {
                    ans++;
                    l = i + 1;
                    break;
                }
            }
        }
        cout <<ans <<endl;
    }
    else
    {
        int ans = 0;
        for (int i = 1;i <= n;i++)
        {
            if (a[i] == r) ans++;
        }
        cout << ans <<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,l,r,sum = 0;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    l = 1;
    r = l;
    for (int i = 1;i <= n;i++)
    {
        int t = 0;
        for (int j = l;j < r;j++)
        {
            t = a[j];
            t = t xor a[j + 1];
        }
        if (t == k)
        {
            l = r + 1;
            r = l;
            sum++;
        }
        else
        {
            r++;
        }
    }
    cout << sum;
    return 0;
}

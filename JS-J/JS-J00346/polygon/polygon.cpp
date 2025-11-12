#include <iostream>
#include <algorithm>
using namespace std;
int k[5000], num, n;
int dfp(int w, int l, int r)
{
    for (int j = w + 1;j < n;j++)
    {
        if (r<2) dfp(j+1, l+k[j + 1], r + 1);
        else
        {
            if (l > k[j+1])
            {
                num++;
                num %= 998244353;
            }
            dfp(j+1,l+ k[j + 1], r + 1);
        }
    }
    return 0;
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> k[i];
    }
    sort(k + 1, k + n + 1);
    for (int i = 1;i <= n;i++)
    {
        dfp(i, k[i], 1);
    }
    cout << num;
}

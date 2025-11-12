#include <bits/stdc++.h>

using namespace std;

/*
int bitlow(int m)
{
    return (m & (~m ^ -m));
}

void build(int n)
{
    int low = bitlow(n);
    for (int i = 1; i <= low - 1; i++)
    {
        lowbit[n] ^= a[n - i];
    }
}
*/

int n, k, a[500005], pre_xor[500005], ans = 0;
bool tmp = 1;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre_xor[i] = a[i];
        pre_xor[i] ^= pre_xor[i - 1];
        if (a[i] != 1)
            tmp = 0;
    }

    if (tmp)
    {
        if (k == 1)
            cout << n;
        if (k == 0)
            cout << (n / 2);
        return 0;
    }

    for (int l = 1; l <= n; l++)
    {
        for (int r = l; r <= n; r++)
        {
            if ((pre_xor[r] ^ pre_xor[l]) == k)
                ans ++;
        }
    }

    if (a[1] == k) ans ++;

    cout << ans;

    return 0;
}

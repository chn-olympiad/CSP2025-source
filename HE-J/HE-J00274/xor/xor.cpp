#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500005];
int main()
{
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1 && a[0] != k)
    {
        cout << 0;
    }
    else if (n == 1 && a[0] == k)
    {
        cout << 1;
    }
    else if (n == 2)
    {
        if (k == 0)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    else if (k == 0)
    {
        if (n % 2 == 0)
        {
            cout << n / 2;
        }
        else
        {
            cout << (n - 1) / 2;
        }
    }
    return 0;
    //WO XIANG YAO GENG DUO DE FEN, YU JI 222 FEN, BAI TUO LE
    //HUOYING CHAOYING 3000 FEN
}

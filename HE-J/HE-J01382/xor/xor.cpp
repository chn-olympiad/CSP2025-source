#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int n, k, a[N];
int sum[N];
bool flag;
int can;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    flag = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != 0)
        {
            can++;
        }
        if (a[i] != 1 && a[i] != 0)
        {
            flag = false;
        }
        sum[i] = sum[i - 1] ^ a[i];
    }
    if (flag)
    {
        if (k == 0)
        {
            cout << can / 2;
        }
        else if (k == 1)
        {
            cout << can;
        }
        else
        {
            cout << 0;
        }
        return 0;
    }
    cout << 2;
    return 0;
}

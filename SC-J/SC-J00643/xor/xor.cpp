#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int a [N], f [N];

int main ()
{
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    int n, k, last = 0, maxn = 0;
    scanf ("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf ("%d", a  + i);
        maxn = max (maxn, a [i]);
        f [i] = f [i - 1];
        int sum = a [i];
        for (int j = i - 1; j >= last; j--)
        {
            if (sum == k)
            {
                f [i] = max (f [i], f [j] + 1);
                break;
            }
            sum ^= a [j];
        }
        if (f [last] != f [i])
        {
            last = i;
        }
    }
    printf ("%d\n", f [n]);
    return 0;
}
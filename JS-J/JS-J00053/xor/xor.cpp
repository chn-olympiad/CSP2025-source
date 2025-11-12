#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
int a[500005];

int Xxor(int l, int r)
{
    if (l == r) return a[l];
    int ans = a[l];
    for (int i = l + 1; i <= r; i ++)
        ans ^= a[i];
    return ans;
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for (int l = 1; l <= n; l ++)
    {
        for (int r = l; r <= n; r ++)
        {
            if (Xxor(l, r) == k)
            {
                ans ++;
                l = r;
                break;
            }
        }
    }
    printf("%d", ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;

int n, k;
int arr[MAXN];
int prefix[MAXN];

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    long long ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += i;
    }
    printf("%lld", ans);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10, M = 2e6 + 10;

int n, k;
int s[N];
int f[N];
int mapping[M];

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d", &s[i]);
        s[i] ^= s[i - 1];
    }

    memset(mapping, -1, sizeof mapping);
    mapping[0] = 0;

    for (int i = 1; i <= n; i ++ )
    {
        int t = s[i] ^ k;
        int pos = mapping[t];
        f[i]= f[i - 1];
        if (pos != -1) f[i] = max(f[i], f[pos] + 1);
        mapping[s[i]] = i;
    }

    printf("%d", f[n]);

    return 0;
}

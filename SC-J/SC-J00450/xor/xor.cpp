#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 9;

int n, m, s[N], f[N], g[N];

void up(int x, int y)
{
    g[x] = max(g[x], y);
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;++ i)
        scanf("%d", &s[i]), s[i] ^= s[i - 1];
    for (int i = 0;i < (1 << 20);++ i)
        g[i] = -1e9;
    up(0, 0);
    for (int i = 1;i <= n;++ i)
        f[i] = max(f[i - 1], g[s[i] ^ m] + 1), up(s[i], f[i]);
    printf("%d\n", f[n]);
    fclose(stdin);
    fclose(stdout);

    return 0;
}
#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 510;

int n;
char str[N];
int c[N], s[N];
int p[N];
int f[N][N];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    scanf("%d%s", &n, str + 1);
    for (int i = 1; i <= n; i ++ )
        s[i] = s[i - 1] + str[i] - '0';
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d", &c[i]);
        int l = 1, r = n + 1; 
        while (l < r)
        {
            int mid = l + r >> 1;
            if (s[mid] >= c[i]) r = mid;
            else l = mid + 1; 
        }
        c[i] = l, p[c[i]] ++ ;
    }
    if (p[n + 1])
    {
        puts("0");
        return 0;
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j <= n; j ++ )
            f[i][j] = (f[i][j] + (LL)f[i - 1][j - p[i] + 1] * j) % mod;
    int ans = 1;
    for (int i = 1; i <= n; i ++ )
        ans = (LL)ans * i % mod;
    printf("%d\n", (ans - f[n][0] + mod) % mod);

    return 0;
}
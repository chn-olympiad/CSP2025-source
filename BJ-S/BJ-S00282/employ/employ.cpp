#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n, m, c[20], quit, pass, p[20], ans;

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d %d", &n, &m);
    string s;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]), p[i] = i;
    do
    {
        quit = pass = 0;
        for (int i = 1; i <= n; i++)
        {
            if (quit >= c[p[i]])
            {
                quit++;
                continue;
            }
            if (s[i] == '1')
            {
                pass++;
            }
            else
            {
                quit++;
            }
        }
        if (pass >= m) ans++;
    } while (next_permutation(p + 1, p + n + 1));
    printf("%d\n", ans);
    return 0;
}
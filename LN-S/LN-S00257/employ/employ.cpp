// 五年老将最后一搏
// 再见了所有的 CSP
// ————学渣李某人 LID： 548505

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 101;

bool s[MAX_N];
int n, m, ans, c[MAX_N], perm[MAX_N];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        char c;

        cin >> c;
        s[i] = c == '1';
    }
    for (int i = 1; i <= n; i++)  { cin >> c[i]; }
    for (int i = 1; i <= n; i++)  { perm[i] = i; }

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        int j = perm[i];

        if (cnt >= c[j] || !s[i])  { cnt++; }
    }
    if (n - cnt >= m)  { ans++; }
    while (next_permutation(perm + 1, perm + n + 1))
    {
        int cnt = 0;

        for (int i = 1; i <= n; i++)
        {
            int j = perm[i];

            if (cnt >= c[j] || !s[i])  { cnt++; }
        }
        if (n - cnt >= m)  { ans++; }
    }
    cout << ans << endl;

    return 0;
}

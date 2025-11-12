#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;
const int MAXN = 2e5 + 1000;
#define int long long

int n, m;

string s;
int c[MAXN];
int p[MAXN];

bool check()
{
    int cnt = 0; // 失败人数
    for (int i = 1; i <= n; i++)
        if (cnt >= c[p[i]] || s[i - 1] == '0')
        {
            cnt++;
            continue;
        }
    return n - cnt >= m;
}

signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    do
    {
        if (check())
            ans++;
    } while (next_permutation(p + 1, p + n + 1));
    cout << ans;
}
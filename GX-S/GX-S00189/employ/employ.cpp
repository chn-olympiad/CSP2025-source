#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int c[505];
int arr[505], larr;
int vis[505];
int ans;
void dfs(int alr)
{
    if (alr == n)
    {
        /*
        for (int i = 1; i <= larr; ++i)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        */
        int att = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (i - att - 1 >= c[arr[i]] || !(s[i - 1] - '0'))
            {
                continue;
            }
            ++att;
            if (att >= m)
            {
                /*
                if (arr[1] == 1 && arr[2] == 2 && arr[3] == 3)
                {

                for (int i = 1; i <= n; ++i)
                {
                    cout << arr[i] << ' ';
                }
                cout << '\n';
                }
                */
                ++ans;
                if (ans == 998244353)
                {
                    ans = 0;
                }
                break;
            }
        }
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
        {
            continue;
        }
        vis[i] = 1;
        arr[++larr] = i;
        dfs(alr + 1);
        --larr;
        vis[i] = 0;
    }
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }
    dfs(0);
    cout << ans;
    return 0;
}

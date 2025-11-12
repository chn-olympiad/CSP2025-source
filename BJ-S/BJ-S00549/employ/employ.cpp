#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

string s;
int n, m;
int c[505], p[505];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        p[i] = i;
    int ans = 0;
    do
    {
        int ok = 0, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (cnt >= c[p[i]])
            {
                cnt++;
                continue;
            }
            if (s[i] == '0')
                cnt++;
            else
                ok++;
        }
        if (ok >= m)
            ans++;
    } while (next_permutation(p + 1, p + 1 + n));
    cout << ans << endl;
    return 0;
}

/*
蒸不动了喵。
只拿 8 分喵。
70 + 64 + 0 + 8 = 142 分，1= 无望了。
可能是因为我是 ** 吧。
*/
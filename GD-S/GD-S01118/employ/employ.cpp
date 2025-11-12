#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, m, ans, cnt, c[505], p[505];
string s;

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (register int i = 1; i <= n; ++i)
    {
        cin >> c[i];
        p[i] = i;
    }
    do
    {
        cnt = 0;
        for (register int i = 1; i <= n && cnt <= n - m; ++i)
        {
            cnt += (s[i - 1] == '0' || cnt >= c[p[i]]);
        }
        ans += (cnt <= n - m);
    } while (next_permutation(p + 1, p + n + 1));
    cout << ans;
    return 0;
}

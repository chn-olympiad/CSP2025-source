#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, ans, c[510], a[510];
string s;

void insert()
{
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++)
        cin >> c[i], a[i] = i;
}

void work()
{
    insert();
    do
    {
        int cnt = 0, ci = 0;
        for(int i = 1; i <= n; i++)
        {
            if(ci < c[a[i]])
            {
                if(s[i - 1] == '1')
                    cnt++;
                else
                    ci++;
            }
            else
                ci++;
        }
        // for(int i = 1; i <= n; i++)
            // cout << a[i] << " ";
        // cout << ci << " " << cnt << '\n';
        if(cnt >= m)
            ans++;
    }while(next_permutation(a + 1, a + n + 1));
    cout << ans << '\n';
}

signed main()
{
    freopen("employ.out", "w", stdout);
    freopen("employ.in", "r", stdin);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    work();
}
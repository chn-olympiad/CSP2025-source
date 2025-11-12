#include<bits/stdc++.h>
using namespace std;

struct lxm
{
    int a, b, c;
}s[100005];
int ans = 0;
int T, n;
bool cmp(lxm x, lxm y)
{
    return x.a > y.a;
}
void dfs(int f, int cnt, int ac, int bc, int cc)
{
    if(f > n)
    {
        ans = max(ans, cnt);
        //cout << ac << " " << bc << " " << cc << endl;
        return;
    }
    if(ac + 1 <= n / 2)
    {
        dfs(f + 1, cnt + s[f].a, ac + 1, bc, cc);
    }
    if(bc + 1 <= n / 2)
    {
        dfs(f + 1, cnt + s[f].b, ac, bc + 1, cc);
    }
    if(cc + 1 <= n / 2)
    {
        dfs(f + 1, cnt + s[f].c, ac, bc, cc + 1);
    }
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        memset(s, 0, sizeof(s));
        ans = 0;
        cin >> n;
        int abc = 0, cba = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> s[i].a >> s[i].b >> s[i].c;
            abc = max(abc, s[i].b);
            cba = max(cba, s[i].c);
        }
        if(abc == 0 && cba == 0)
        {
            sort(s + 1, s + n + 1, cmp);
            int cnt = 0;
            for(int i = 1; i <= n / 2; i++)
            {
                cnt += s[i].a;
            }
            cout << cnt;
            continue;
        }
        dfs(1, 0, 0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}

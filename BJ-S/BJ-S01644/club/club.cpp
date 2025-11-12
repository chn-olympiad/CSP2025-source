#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005], b[100005], c[100005], ans, go[4], p[100005];
void dfs(int x)
{
    if(x > n)
    {
        int xx = 0;
        for(int i = 1;i <= n;i ++)
        {
            if(p[i] == 1) xx += a[i];
            else if(p[i] == 2) xx += b[i];
            else xx += c[i];
        }
        ans = max(ans, xx);
        return;
    }
    for(int i = 1;i <= 3;i ++)
    {
        if(go[i] < n / 2)
        {
            go[i] ++;
            p[x] = i;
            dfs(x + 1);
            go[i] --;
        }
    }
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t --)
    {
        cin >> n;
        ans = 0;
        int flag = 0;
        for(int i = 1;i <= 3;i ++) go[i] = 0;
        for(int i = 1;i <= n;i ++)
        {
            cin >> a[i] >> b[i] >> c[i];
            flag += b[i] + c[i];
        }
        if(!flag)
        {
            sort(a + 1, a + n + 1);
            for(int i = n;i > n / 2;i --) ans += a[i];
            cout << ans << '\n';
        }
        else
        {
            dfs(1);
            cout << ans << '\n';
        }
     }
    return 0;
}
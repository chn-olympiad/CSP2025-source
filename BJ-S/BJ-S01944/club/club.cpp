#include <bits/stdc++.h>
#define it long long
using namespace std;
struct node
{
    it v, p, id;
} a[300005];
it s[5];
bool vis[300005];
it cal(it x, it y, it z)
{
    if(x < y) swap(x, y);
    if(x < z) swap(x, z);
    if(y < z) swap(y, z);
    return y;
}
bool cmp(node x, node y)
{
    return x.v > y.v;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    it t, cnt;
    cin >> t;
    while(t--)
    {
        //memset(s, 0, sizeof(s));
        s[1] = s[2] = s[3] = 0;
        cnt = 0;
        it ans = 0;
        it n;
        cin >> n;
        for(it i = 1; i <= n;i++)
        {
            for(it j = 1; j <= 3;j++)
            {
                cin >> a[++cnt].v;
                a[cnt].p = j, a[cnt].id = i;
            }
            vis[i] = 0;
            it minn = cal(a[cnt].v, a[cnt - 1].v, a[cnt - 2].v);
            a[cnt - 2].v -= minn, a[cnt - 1].v -= minn, a[cnt].v -= minn;
            ans += minn;
        }
        sort(a + 1, a + cnt + 1, cmp);
        for(int i = 1; i <= cnt;i++)
        {
            if(s[a[i].p] < (n / 2) && !vis[a[i].id])
            {
                s[a[i].p]++;
                vis[a[i].id] = 1;
                ans += a[i].v;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

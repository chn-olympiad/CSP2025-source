#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;

struct Node
{
    int v, id;
} a[N + 5], b[N + 5], c[N + 5];

int T, n;
ll ans;
int f, s, t, x, y, z, cnt1, cnt2, cnt3, p[N + 5][5];
bool vis[N + 5];

bool cmp(Node x, Node y)
{
    return x.v > y.v;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        ans = 0;
        cin >> n;
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> x >> y >> z;
            a[i].v = x - max(y, z);
            b[i].v = y - max(x, z);
            c[i].v = z - max(x, y);
            a[i].id = b[i].id = c[i].id = i;
            vis[i] = 0;
            p[i][1] = x;
            p[i][2] = y;
            p[i][3] = z;
        }
        sort(a + 1, a + n + 1, cmp);
        sort(b + 1, b + n + 1, cmp);
        sort(c + 1, c + n + 1, cmp);
        f = s = t = 1;
        cnt1 = cnt2 = cnt3 = 0;
        int m = n;
        while (m--)
        {
            if ((a[f].v >= b[s].v || cnt2 >= n / 2) && (a[f].v >= c[t].v || cnt3 >= n / 2) && cnt1 < n / 2 && f <= n)
            {
                vis[a[f].id] = 1;
                ans += p[a[f].id][1];
                f++;
                cnt1++;
            }
            else if ((b[s].v >= a[f].v || cnt1 >= n / 2) && (b[s].v >= c[t].v || cnt3 >= n / 2) && cnt2 < n / 2 && s <= n)
            {
                vis[b[s].id] = 1;
                ans += p[b[s].id][2];
                s++;
                cnt2++;
            }
            else
            {
                vis[c[t].id] = 1;
                ans += p[c[t].id][3];
                t++;
                cnt3++;
            }
            while (vis[a[f].id]) f++;
            while (vis[b[s].id]) s++;
            while (vis[c[t].id]) t++;
        }
        cout << ans << "\n";
    }
    return 0;
}

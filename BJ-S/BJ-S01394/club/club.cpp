//15:10
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node
{
    int id;
    int u, v;
    int val;
};
bool operator< (node x, node y)
{
    return x.val > y.val;
}
int a[N][4];
int to[N], cnt[4];
int calc(int i)
{
    return max(a[i][1], max(a[i][2], a[i][3]));
}
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T --)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= 3; j ++)
                cin >> a[i][j];
        priority_queue<node> q[4];
        cnt[1] = cnt[2] = cnt[3] = 0;
        for (int i = 1; i <= n; i ++)
        {
            if (a[i][1] == calc(i))
            {
                to[i] = 1, cnt[1] ++;
                q[1].push({i, 1, 2, a[i][1] - a[i][2]});
                q[1].push({i, 1, 3, a[i][1] - a[i][3]});
            }
            else if (a[i][2] == calc(i))
            {
                to[i] = 2, cnt[2] ++;
                q[2].push({i, 2, 1, a[i][2] - a[i][1]});
                q[2].push({i, 2, 3, a[i][2] - a[i][3]});
            }
            else if (a[i][3] == calc(i))
            {
                to[i] = 3, cnt[3] ++;
                q[3].push({i, 3, 1, a[i][3] - a[i][1]});
                q[3].push({i, 3, 2, a[i][3] - a[i][2]});
            }
        }
        // cout << cnt[1] << " " << cnt[2] << " " << cnt[3] << "\n";
        if (cnt[1] > n / 2)
        {
            while (cnt[1] > n / 2)
            {
                while (to[q[1].top().id] != q[1].top().u) q[1].pop();
                cnt[1] --, cnt[q[1].top().v] ++;
                to[q[1].top().id] = q[1].top().v;
                q[1].pop();
            }
        }
        if (cnt[2] > n / 2)
        {
            while (cnt[2] > n / 2)
            {
                while (to[q[2].top().id] != q[2].top().u) q[2].pop();
                cnt[2] --, cnt[q[2].top().v] ++;
                to[q[2].top().id] = q[2].top().v;
                q[2].pop();
            }
        }
        if (cnt[3] > n / 2)
        {
            while (cnt[3] > n / 2)
            {
                while (to[q[3].top().id] != q[3].top().u) q[3].pop();
                cnt[3] --, cnt[q[3].top().v] ++;
                to[q[3].top().id] = q[3].top().v;
                q[3].pop();
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i ++)
            ans += a[i][to[i]];
        cout << ans << "\n";
    }

    return 0;
}
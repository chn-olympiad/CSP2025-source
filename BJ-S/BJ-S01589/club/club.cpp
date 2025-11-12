#include <bits/stdc++.h>
using namespace std;
#define For(i, x, y) for (int i = x; i <= y; i++)
#define foR(i, x, y) for (int i = x, i >= y; i--)
#define vector basic_string
typedef pair<int, int> pii;
const int N = 1e5 + 5;
int n, a[N][3], b[N];

void reset()
{

}

struct node
{
    int val, u, v;
    bool operator<(const node t) const
    {
        return val < t.val;
    }
};
void solve()
{
    scanf("%d", &n);
    int ans = 0;
    int cnt[3] = {0, 0, 0};
    For (i, 1, n)
    {
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
        int mx = max({a[i][0], a[i][1], a[i][2]});
        ans += mx;
        if (a[i][0] == mx)
            cnt[0]++, b[i] = 0;
        else if (a[i][1] == mx)
            cnt[1]++, b[i] = 1;
        else
            cnt[2]++, b[i] = 2;
    }
    int p[4] = {0, 1, 2};
    if (cnt[p[0]] < cnt[p[1]])
        swap(p[0], p[1]);
    if (cnt[p[1]] < cnt[p[2]])
        swap(p[1], p[2]);
    if (cnt[p[0]] < cnt[p[1]])
        swap(p[0], p[1]);
    priority_queue<pii> q01, q02, q12, q21;
    For (i, 1, n)
    {
        int t[3] = {a[i][p[0]], a[i][p[1]], a[i][p[2]]};
        a[i][0] = t[0], a[i][1] = t[1], a[i][2] = t[2];
        int mx = max({a[i][0], a[i][1], a[i][2]});
        if (a[i][0] == mx)
            b[i] = 0, q01.push({a[i][1] - a[i][0], i}), q02.push({a[i][2] - a[i][0], i});
        else if (a[i][1] == mx)
            b[i] = 1, q12.push({a[i][2] - a[i][1], i});
        else
            b[i] = 2, q21.push({a[i][1] - a[i][2], i});
        // cerr << a[i][0] << ' ' << a[i][1] << ' ' << a[i][2] << endl;
    }
    sort(cnt, cnt + 3, greater<int>());
    // cerr << "!" << endl;
    while (cnt[0] > n / 2)
    {
        // cerr << "." << endl;
        int cur = -0x3f3f3f3f;
        // cerr << q01.size() << endl;
        while (!q01.empty() && b[q01.top().second] != 0)
            q01.pop();
        // cerr << "+" << endl;
        while (!q02.empty() && b[q02.top().second] != 0)
            q02.pop();
        while (!q12.empty() && b[q12.top().second] != 1)
            q12.pop();
        while (!q21.empty() && b[q21.top().second] != 2)
            q21.pop();
        if (cnt[1] < n / 2)
            cur = max(cur, q01.top().first);
        if (cnt[2] < n / 2)
            cur = max(cur, q02.top().first);
        if (cnt[1] < n / 2 && !q21.empty())
            cur = max(cur, q21.top().first + q02.top().first);
        if (cnt[2] < n / 2 && !q12.empty())
            cur = max(cur, q12.top().first + q01.top().first);
        ans += cur;
        if (cnt[1] < n / 2 && cur == q01.top().first)
        {
            int u = q01.top().second;
            b[u] = 1, cnt[0]--;
            q01.pop();
            q12.push({a[u][2] - a[u][1], u});
        }
        else if (cnt[2] < n / 2 && cur == q02.top().first)
        {
            int u = q02.top().second;
            b[u] = 2, cnt[0]--;
            q02.pop();
            q21.push({a[u][1] - a[u][2], u});
        }
        else if (cnt[1] < n / 2 && !q21.empty() && cur == q21.top().first + q02.top().first)
        {
            int u = q02.top().second, v = q21.top().second;
            b[u] = 2, b[v] = 1;
            q02.pop(), q21.pop();
            q21.push({a[u][1] - a[u][2], u});
            q12.push({a[v][2] - a[v][1], v});
        }
        else if (cnt[2] < n / 2 && !q12.empty() && cur == q12.top().first + q01.top().first)
        {
            int u = q01.top().second, v = q12.top().second;
            b[u] = 1, b[v] = 2;
            q01.pop(), q12.pop();
            q12.push({a[u][2] - a[u][1], u});
            q21.push({a[v][1] - a[v][2], v});
        }
        // cerr << cnt[0] << endl;
    }
    printf("%d\n", ans);
    // cerr << "end" << endl;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
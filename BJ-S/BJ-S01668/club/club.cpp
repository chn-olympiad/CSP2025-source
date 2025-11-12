#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1e5 + 5;
int T, n, a[N][4], ans = -1;

struct Node
{
    int i, v, a, b, c;
};

int main()
{
    ios::sync_with_stdio(false);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 3; j++)
                cin >> a[i][j];
        for (int j = 1; j <= 3; j++) a[n + 1][j] = 0;
        queue<Node> q;
        q.push({0, 0, 0, 0, 0});
        ans = -1;
        while (!q.empty())
        {
            Node p = q.front();
            q.pop();
            if (p.i > n)
            {
                ans = max(ans, p.v);
                continue;
            }
            int i = p.i + 1;
            if (p.a < n / 2) q.push({i, p.v + a[i][1], p.a + 1, p.b, p.c});
            if (p.b < n / 2) q.push({i, p.v + a[i][2], p.a, p.b + 1, p.c});
            if (p.c < n / 2) q.push({i, p.v + a[i][3], p.a, p.b, p.c + 1});
        }
        cout << ans << endl;
    }
    return 0;
}

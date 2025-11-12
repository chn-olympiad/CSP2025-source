#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5;

int n;
PII a[N + 5][3];
priority_queue<int, vector<int>, greater<int>> heap[3];

int main()
{
    // 写 freopen!
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cin >> a[i][j].first;
                a[i][j].second = j;
            }
            stable_sort(a[i], a[i] + 3);
            reverse(a[i], a[i] + 3);
        }

        for (int i = 0; i < 3; ++i)
            while (!heap[i].empty())
                heap[i].pop();

        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            auto &cur = heap[a[i][0].second];
            ans += a[i][0].first;
            cur.push(a[i][0].first - a[i][1].first);
            if (cur.size() > n / 2) // 超过限制
            {
                ans -= cur.top();
                cur.pop();
            }
        }
        cout << ans << endl;
    }

    return 0;
}
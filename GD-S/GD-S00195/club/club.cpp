#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 1e5 + 10;
using it2 = array<int, 2>;
using it23 = array<it2, 3>;

int n, a[N][3], cnt[3], ans;
it23 b[N];

template <typename Tp>
void sort(array<Tp, 3> &x)
{
    if (x[0] < x[1])
    {
        swap(x[0], x[1]);
    }
    if (x[1] < x[2])
    {
        swap(x[1], x[2]);
    }
    if (x[0] < x[1])
    {
        swap(x[0], x[1]);
    }
}

signed main()
{
    if (1)
    {
        freopen("club.in", "r", stdin);
        freopen("club.out", "w", stdout);
    }
    cin.tie(0)->sync_with_stdio(0), cout << fixed << setprecision(10);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            b[i][0] = {a[i][0], 0}, b[i][1] = {a[i][1], 1}, b[i][2] = {a[i][2], 2};
            sort(b[i]);
        }
        cnt[0] = cnt[1] = cnt[2] = ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq[3];
        for (int i = 1, w, id, w_; i <= n; ++i)
        {
            w = b[i][0][0], id = b[i][0][1], w_ = b[i][1][0];
            if (cnt[id] == n / 2)
            {
                int cost = pq[id].top();
                if (w - w_ > cost)
                {
                    ans += w - cost;
                    pq[id].pop();
                    pq[id].push(w - w_);
                }
                else
                {
                    ans += w_;
                }
            }
            else
            {
                ans += w, ++cnt[id];
                pq[id].push(w - w_);
            }
        }
        cout << ans << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

int t, n, b[100005], cnt[100005], ans, x2, y2, max1, max2, max3;

struct A
{
    int x, y;
}a[100005][5];

bool cmp(int x, int y)
{
    return x > y;
}



int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q[10];
        ans = 0;
        memset(cnt, 0, sizeof cnt);
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i][1].x >> a[i][2].x >> a[i][3].x;
            a[i][1].y = 1;
            a[i][2].y = 2;
            a[i][3].y = 3;
            x2 = 0, y2 = 0;
            for (int j = 1; j <= 3; j++)
            {
                if (a[i][j].x > x2)
                {
                    x2 = a[i][j].x;
                    y2 = j;
                }
            }
            ans += x2;
            b[i] = y2;
            cnt[y2]++;
        }
        int maxn = max({cnt[1], cnt[2], cnt[3]});
        int minn = min({cnt[1], cnt[2], cnt[3]});
        if (cnt[1] == maxn)
        {
            max1 = 1;
        }
        else if (cnt[2] == maxn)
        {
            max1 = 2;
        }
        else
        {
            max1 = 3;
        }
        if (cnt[2] == minn)
        {
            max3 = 2;
        }
        else if (cnt[3] == minn)
        {
            max3 = 3;
        }
        else
        {
            max3 = 1;
        }
        if (max1 != 1 && max3 != 1)
        {
            max2 = 1;
        }
        else if (max1 != 3 && max3 != 3)
        {
            max2 = 3;
        }
        else
        {
            max2 = 2;
        }
        
        for (int i = 1; i <= n; i++)
        {
            if (b[i] == max1)
            {
                if (a[i][max1].x - a[i][max2].x < a[i][max1].x - a[i][max3].x)
                q[max1].emplace(a[i][max1].x - a[i][max2].x, i);
                else
                q[max1 + 3].emplace(a[i][max1].x - a[i][max3].x, i);
            }
            if (b[i] == max2)
            q[max2].emplace(a[i][max2].x - a[i][max3].x, i);
            if (b[i] == max3)
            q[max3].emplace(a[i][max3].x - a[i][max2].x, i);
        }
        if (cnt[max1] <= n / 2)
        {
            cout << ans << endl;
            continue;
        }
        while (cnt[max1] > n / 2)
        {
            cnt[max1]--;
            if (!q[max1 + 3].empty() && q[max1].empty())
            {
                auto [x3, y3] = q[max1 + 3].top();
                ans -= x3;
                cnt[max3]++;
                q[max3].emplace(a[y3][max3].x - a[y3][max2].x, y3);
                q[max1 + 3].pop();
            }
            else if (!q[max1].empty() && q[max1 + 3].empty())
            {
                auto [x3, y3] = q[max1].top();
                ans -= x3;
                cnt[max3]++;
                q[max3].emplace(a[y3][max2].x - a[y3][max3].x, y3);
                q[max1].pop();
            }
            else
            {
                auto [x3, y3] = q[max1 + 3].top();
                auto [x, y] = q[max1].top();
                if (x3 < x)
                {
                    ans -= x3;
                    cnt[max3]++;
                    q[max3].emplace(a[y][max3].x - a[y][max2].x, y);
                    q[max1 + 3].pop();
                }
                else
                {
                    ans -= x;
                    cnt[max2]++;
                    q[max2].emplace(a[y][max2].x - a[y][max3].x, y);
                    q[max1].pop();
                }
            }
            
            
            
        }
        while (cnt[max2] > n / 2)
        {
            cnt[max2]--;
            cnt[max3]++;
            auto [x, y] = q[max2].top();
            ans -= x;
            q[max2].pop();
            q[max3].emplace(a[y][max3].x - a[y][max2].x, y);

        }
        while (cnt[max3] > n / 2)
        {
            cnt[max3]--;
            cnt[max2]++;
            auto [x, y] = q[max3].top();
            ans -= x;
            q[max3].pop();
            q[max2].emplace(a[y][max2].x - a[y][max3].x, y);

        }
        
        cout << ans << endl;
    }
    return 0;
}
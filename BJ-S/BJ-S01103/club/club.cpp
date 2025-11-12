#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int a[N][5], aa[N], ab[N], ac[N];
int n;
struct node
{
    int id;
    int x, y, z;
    int d12;
};
bool operator<(node p, node q)
{
    return p.d12 <= q.d12;
}
priority_queue<node> pq1, pq2;
long long ans, anss;
void dfs(int ren, int cnt1, int cnt2, int cnt3)
{
    if (cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2) return;
    if (ren > n)
    {
        ans = max(ans, anss);
        return ;
    }
    anss += a[ren][1];
    dfs(ren + 1, cnt1 + 1, cnt2, cnt3);
    anss -= a[ren][1];
    anss += a[ren][2];
    dfs(ren + 1, cnt1, cnt2 + 1, cnt3);
    anss -= a[ren][2];
    anss += a[ren][3];
    dfs(ren + 1, cnt1, cnt2, cnt3 + 1);
    anss -= a[ren][3];
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        bool f1 = 0, f2 = 0, f3 = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            aa[i] = a[i][1];
            ab[i] = a[i][2];
            ac[i] = a[i][3];
            if (a[i][3] != 0)
            {
                f3 = 1;
            }
            if (a[i][2] != 0)
            {
                f2 = 1;
            }
            if (a[i][1] != 0)
            {
                f1 = 1;
            }
        }
        if (f1 == 0 && f2 == 0 && f3 == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (f2 == 0 && f3 == 0)
        {
            long long sum = 0;
            sort(aa + 1, aa + n + 1);
            for (int i = n / 2 + 1; i <= n; i++)
            {
                sum += aa[i];
            }
            cout << sum << endl;
            continue;
        }
        if (f2 == 0 && f1 == 0)
        {
            long long sum = 0;
            sort(ac + 1, ac + n + 1);
            for (int i = n / 2 + 1; i <= n; i++)
            {
                sum += ac[i];
            }
            cout << sum << endl;
            continue;
        }
        if (f1 == 0 && f3 == 0)
        {
            long long sum = 0;
            sort(ab + 1, ab + n + 1);
            for (int i = n / 2 + 1; i <= n; i++)
            {
                sum += ab[i];
            }
            cout << sum << endl;
            continue;
        }
        if (f3 == 0 || f2 == 0 || f1 == 0)
        {
            while (!pq1.empty())
            {
                pq1.pop();
            }
            while (!pq2.empty())
            {
                pq2.pop();
            }
            int r1, r2;
            if (f1 == 0)
            {
                r1 = 2, r2 = 3;
            }
            if (f2 == 0)
            {
                r1 = 1, r2 = 3;
            }
            if (f3 == 0)
            {
                r1 = 1, r2 = 2;
            }
            long long sum = 0;
            for (int i = 1; i <= n/2; i++)
            {
                node t;
                t.id = i;
                t.x = a[i][r1];
                t.y = a[i][r2];
                //t.z = a[i][3];
                t.d12 = a[i][r2] - a[i][r1];
                pq1.push(t);
                sum += t.x;
            }
            for (int i = n / 2 + 1; i <= n; i++)
            {
                node t;
                t.id = i;
                t.x = a[i][r1];
                t.y = a[i][r2];
                //t.z = a[i][3];
                t.d12 = a[i][r1] - a[i][r2];
                pq2.push(t);
                sum += t.y;
            }
            while (pq1.top().d12 + pq2.top().d12 > 0)
            {
                node t1 = pq1.top(), t2 = pq2.top();
                sum += t1.d12 + t2.d12;
                t1.d12 = -t1.d12;
                t2.d12 = -t2.d12;
                pq1.pop();
                pq2.pop();
                pq1.push(t2);
                pq2.push(t1);
            }
            cout << sum << endl;
            continue;
        }
        if (n == 2)
        {
            int maxn = 0;
            for (int i = 1; i <= 3; i++)
            {
                for (int j = 1; j <= 3; j++)
                {
                    if (i == j) continue;
                    maxn = max(maxn, a[1][i] + a[2][j]);
                }
            }
            cout << maxn << endl;
            continue;
        }
        ans = 0, anss = 0;
        dfs(1, 0, 0, 0);
        cout << ans << endl;
    }

    return 0;
}

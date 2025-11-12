#include <bits/stdc++.h>
#define pii pair<int, pair <int, int> >
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll n, a[N][4], r[4], t;
void init_()
{
    r[0] = r[1] = r[2] = 0;
    ll ans = 0;
    cin >> n;
    priority_queue<pii, vector <pii>, greater <pii> > pq[4]; 
    for (int i = 1; i <= n; i ++)
    {
        ll z = INT_MAX;
        for (int j = 0; j < 3; j ++)
        {
            cin >> a[i][j];
            z = min (z, a[i][j]);
        }
        ans += z;
        ll x = 0, y = 0, x1, y1;
        for (int j = 0; j < 3; j ++)
        {
            a[i][j] -= z;
            if (a[i][j] > x)
            {
                y = x;
                y1 = x1;
                x = a[i][j];
                x1 = j;
            }
            else if (a[i][j] > y)
            {
                y = a[i][j];
                y1 = j;
            }
        }
        if (pq[x1].size() < n / 2) {pq[x1].push(pii {x, pair <int, int> {i, y1}}); r[x1] += x;}
        else
        {
            if (pq[x1].top().first < x1)
            {
                ll op = pq[x1].top().second.second;
                ll op2 = pq[x1].top().second.first;
                pq[op].push(pii {a[op2][op], pair <int, int> {op2, 3 - x1 - op}});
                pq[x1].pop();
                r[op] += a[op2][op];
                r[x1] -= pq[x1].top().first;
                r[x1] += x;
                pq[x1].push(pii {x, pair <int, int> {i, y1}});
            }
            else
            {
                r[y1] += y;
                pq[y1].push(pii {y, pair <int, int> {i, 3 - y1 - x1}});
            }
        }
    }
    cout << ans + r[0] + r[1] + r[2] << endl;
}
int main()
{
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    cin >> t;
    while (t --) {init_(); }
    return 0;
}
//Ren5Jie4Di4Ling5%
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
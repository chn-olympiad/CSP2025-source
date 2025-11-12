#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    ll val, id;
} a[105];
ll n, m;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i].val;
        a[i].id = i;
    }
    sort(a + 1, a + n * m + 1, [](node a, node b){return a.val > b.val;});
    for (int i = 1; i <= n * m; i++)
    {
        ll c = (i + n - 1) / n, r = (i - 1) % n + 1;
        if (c % 2 == 0) r = n - r + 1;
        if (a[i].id == 1)
        {
            cout << c << ' ' << r << '\n';
            return 0;
        }
    }
    cout << '\n';
    return 0;
}

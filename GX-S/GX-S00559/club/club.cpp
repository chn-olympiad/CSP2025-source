#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, x, y, z, ans = 0, d[N];
vector <ll> num[4];
void solve()
{
    ans = 0;
    num[1].clear();
    num[2].clear();
    num[3].clear();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        ll maxx = x, sum = 0;
        maxx = max(maxx, y);
        maxx = max(maxx, z);
        sum += (maxx == x);
        sum += (maxx == y);
        sum += (maxx == z);
        if (sum == 1)
        {
            if (maxx == x)
                num[1].push_back(i);
            if (maxx == y)
                num[2].push_back(i);
            if (maxx == z)
                num[3].push_back(i);
        }
        if (x > y)
            swap(x, y);
        if (x > z)
            swap(x, z);
        if (y > z)
            swap(y, z);
        d[i] = z - y;
        ans += z;
    }
    int s = 0;
    for (int i = 1; i <= 3; i++)
        if (num[i].size() > n / 2)
            s = i;
    if (s == 0)
        return cout << ans << endl, void();
    sort(num[s].begin(), num[s].end(), [](int x, int y){
        return d[x] < d[y];
    });
    for (int i = 0; i < num[s].size() - n / 2; i++)
        ans -= d[num[s][i]];
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

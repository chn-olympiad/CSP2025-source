#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 500005;
int n, k, a[N];
long long cnt;
vector<pair<int, int>> ve;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    bool f = 1;
    for (int i = 1; i <= n; i++)
        if (a[i] != 1)
        {
            f = 0;
            break;
        }
    if (k == 0 && f)
    {
        cout << n / 2;
        return 0;
    }

    f = 1;
    for (int i = 1; i <= n; i++)
        if (a[i] != 1 && a[i] != 0)
        {
            f = 0;
            break;
        }
    if (k == 0 && f)
    {
        int cnt = 0, now = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == 0)
                cnt++;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 1)
                now++;
            else
            {
                cnt += now / 2;
                now = 0;
            }
        }
        if (now)
            cnt += now / 2;
        cout << cnt;
        return 0;
    }
    if (k == 1 && f)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == 1)
                cnt++;
        cout << cnt;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == k)
            ve.push_back(make_pair(i, i));
        int res = a[i];
        for (int j = i + 1; j <= n; j++)
        {
            res ^= a[j];
            if (res == k)
                ve.push_back(make_pair(j, i));
        }
    }
    sort(ve.begin(), ve.end());
    int _l = 0, _r = 0;
    for (auto x : ve)
    {
        if (x.second  > _r)
        {
            cnt++;
            _l = x.second;
            _r = x.first;
        }
    }
    cout << cnt;
    return 0;
}

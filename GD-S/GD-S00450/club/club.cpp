#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 2e5;

int a[MAXN][4];
int ans = 0;

int getmaxid(int i)
{
    if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
        return 1;
    if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
        return 2;
    return 3;
}

int getval(int i, int id)
{
    if (id == 1)
        return a[i][1] - max(a[i][2], a[i][3]);
    if (id == 2)
        return a[i][2] - max(a[i][1], a[i][3]);
    if (id == 3)
        return a[i][3] - max(a[i][2], a[i][1]);
    return 0;
}

vector<int> lst[4];
int n;

void solve2(int id)
{
    vector<int> vec;
    for (int i = 0; i < lst[id].size(); i++)
        vec.push_back(getval(lst[id][i], id));
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size() - (n / 2); i++)
        ans -= vec[i];
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i][1] >> a[i][2] >> a[i][3];
    lst[1].clear();
    lst[2].clear();
    lst[3].clear();
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int id = getmaxid(i);
        lst[id].push_back(i);
        ans += a[i][id];
    }
    for (int i = 1; i <= 3; i++)
        if (lst[i].size() > n / 2)
            solve2(i);

    cout << ans << "\n";
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
        solve();
}
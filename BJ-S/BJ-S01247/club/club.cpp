#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int a[maxn][3];
vector<int> vec[3];

void work()
{
    int n, sum = 0; cin >> n;
    vec[0].clear(), vec[1].clear(), vec[2].clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        int mx = max(max(a[i][0], a[i][1]), a[i][2]); sum += mx;
        if (mx == a[i][0]) vec[0].emplace_back(i);
        else if (mx == a[i][1]) vec[1].emplace_back(i);
        else vec[2].emplace_back(i);
    }

    int m = n >> 1;
    if (vec[0].size() <= m && vec[1].size() <= m && vec[2].size() <= m) return cout << sum << "\n", void();
    if (vec[0].size() > m)
    {
        sort(vec[0].begin(), vec[0].end(), [&](int x, int y) { return max(a[x][1], a[x][2]) - a[x][0] < max(a[y][1], a[y][2]) - a[y][0]; });
        while (vec[0].size() > m)
        {
            int x = vec[0].back();
            sum += max(a[x][1], a[x][2]) - a[x][0];
            vec[0].pop_back();
        }
        cout << sum << "\n"; return;
    }
    if (vec[1].size() > m)
    {
        sort(vec[1].begin(), vec[1].end(), [&](int x, int y) { return max(a[x][0], a[x][2]) - a[x][1] < max(a[y][0], a[y][2]) - a[y][1]; });
        while (vec[1].size() > m)
        {
            int x = vec[1].back();
            sum += max(a[x][0], a[x][2]) - a[x][1];
            vec[1].pop_back();
        }
        cout << sum << "\n"; return;
    }
    if (vec[2].size() > m)
    {
        sort(vec[2].begin(), vec[2].end(), [&](int x, int y) { return max(a[x][1], a[x][0]) - a[x][2] < max(a[y][1], a[y][0]) - a[y][2]; });
        while (vec[2].size() > m)
        {
            int x = vec[2].back();
            sum += max(a[x][1], a[x][0]) - a[x][2];
            vec[2].pop_back();
        }
        cout << sum << "\n"; return;
    }
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);

    int T; cin >> T;
    while (T--) work();
    return 0;
}
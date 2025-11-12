#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int a[100005][5];
vector<int> v[5];
long long res = 0;

int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (isdigit(c))
        x *= 10, x += c - '0', c = getchar();
    return x * f;
}

void write(long long x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    // cin >> T;
    T = read();
    while (T--)
    {
        v[1].clear(), v[2].clear(), v[3].clear();
        res = 0;
        // cin >> n;
        n = read();
        for (int i = 1; i <= n; i++)
        {
            // cin >> a[i][1] >> a[i][2] >> a[i][3];
            a[i][1] = read(), a[i][2] = read(), a[i][3] = read();
            if (a[i][1] >= a[i][2] and a[i][1] >= a[i][3])
                v[1].push_back(i), res += a[i][1];
            else if (a[i][2] >= a[i][1] and a[i][2] >= a[i][3])
                v[2].push_back(i), res += a[i][2];
            else
                v[3].push_back(i), res += a[i][3];
        }
        if (v[1].size() * 2 > n)
        {
            sort(v[1].begin(), v[1].end(), [&] (int x, int y) {
                return max(a[x][2], a[x][3]) - a[x][1] < max(a[y][2], a[y][3]) - a[y][1];
            });
            while (v[1].size() * 2 > n)
            {
                int p = v[1].back();
                res += max(a[p][2], a[p][3]) - a[p][1];
                v[1].pop_back();
            }
            // cout << res << "\n";
            write(res), putchar('\n');
        }
        else if (v[2].size() * 2 > n)
        {
            sort(v[2].begin(), v[2].end(), [&] (int x, int y) {
                return max(a[x][1], a[x][3]) - a[x][2] < max(a[y][1], a[y][3]) - a[y][2];
            });
            while (v[2].size() * 2 > n)
            {
                int p = v[2].back();
                res += max(a[p][1], a[p][3]) - a[p][2];
                v[2].pop_back();
            }
            // cout << res << "\n";
            write(res), putchar('\n');
        }
        else if (v[3].size() * 2 > n)
        {
            sort(v[3].begin(), v[3].end(), [&] (int x, int y) {
                return max(a[x][2], a[x][1]) - a[x][3] < max(a[y][2], a[y][1]) - a[y][3];
            });
            while (v[3].size() * 2 > n)
            {
                int p = v[3].back();
                res += max(a[p][2], a[p][1]) - a[p][3];
                v[3].pop_back();
            }
            // cout << res << "\n";
            write(res), putchar('\n');
        }
        else
        {
            // cout << res << "\n";
            write(res), putchar('\n');
        }
    }
}
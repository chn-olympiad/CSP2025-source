#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, sz;
vector<int> g, pos, id;

bool compare(int a, int b)
{
    return g[a] > g[b];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;

    sz = n * m;
    g.resize(sz + 1);
    pos.resize(sz + 1);
    id.resize(sz + 1);

    for (int i = 1; i <= sz; i++)
    {
        pos[i] = i;
    }

    for (int i = 1; i <= sz; i++)
    {
        cin >> g[i];
    }

    sort(pos.begin() + 1, pos.end(), compare);

    for (int i = 1; i <= sz; i++)
    {
        id[pos[i]] = i;
    }

    int fpos = id[1], fi = ceil(fpos * 1.0 / n);

    cout << fi << ' ';

    if (fi % 2 == 0)
    {
        int se = n - (fpos % n) + 1;
        if (se > n)
        {
            cout << 1;
        }
        else
        {
            cout << se;
        }
    }
    else
    {
        int se = fpos % n;
        if (se == 0)
        {
            cout << n;
        }
        else
        {
            cout << se;
        }
    }

    return 0;
}

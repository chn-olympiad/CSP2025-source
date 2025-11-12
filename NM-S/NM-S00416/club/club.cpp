#include <bits/stdc++.h>
using namespace std;

int t, n, ans;
struct Member
{
    int v[3], f[3];
    int k, j;

} m[100000];
int s[3][100000], l[3];
int a, b, c;

inline int ins(int a, int b)
{
    int l_ = -1, r = l[a];
    while (l_ < r - 1)
    {
        if (m[s[a][(l_ + r) >> 1]].j > b)
            l_ = (l_ + r) >> 1;
        else
            r = (l_ + r) >> 1;
    }
    return r;
}
inline void calc(Member &m, const int &x, const int &y, const int &z)
{
    m.v[0] = x, m.v[1] = y, m.v[2] = z;
    if (x >= y && y >= z)
        m.f[0] = 0, m.f[1] = 1, m.f[2] = 2;
    else if (x >= z && z >= y)
        m.f[0] = 0, m.f[1] = 2, m.f[2] = 1;
    else if (y >= x && x >= z)
        m.f[0] = 1, m.f[1] = 0, m.f[2] = 2;
    else if (y >= z && z >= x)
        m.f[0] = 1, m.f[1] = 2, m.f[2] = 0;
    else if (z >= y && y >= x)
        m.f[0] = 2, m.f[1] = 1, m.f[2] = 0;
    else if (z >= x && x >= y)
        m.f[0] = 2, m.f[1] = 0, m.f[2] = 1;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        ans = l[0] = l[1] = l[2] = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b >> c;
            calc(m[i], a, b, c);
            m[i].j = m[i].v[m[i].f[0]] - m[i].v[m[i].f[0 + 1]];
            int ind = ins(m[i].f[0], m[i].j);
            memmove(s[m[i].f[0]] + ind + 1, s[m[i].f[0]] + ind, (l[m[i].f[0]] - ind) * sizeof(int));
            s[m[i].f[0]][ind] = i, m[i].k = 0;
            l[m[i].f[0]]++;
            if (l[m[i].f[0]] > n / 2)
            {
                m[s[m[i].f[0]][l[m[i].f[0]] - 1]].k++;
                m[s[m[i].f[0]][l[m[i].f[0]] - 1]].j = m[s[m[i].f[0]][l[m[i].f[0]] - 1]].v[m[s[m[i].f[0]][l[m[i].f[0]] - 1]].f[m[s[m[i].f[0]][l[m[i].f[0]] - 1]].k]] - m[s[m[i].f[0]][l[m[i].f[0]] - 1]].v[m[s[m[i].f[0]][l[m[i].f[0]] - 1]].f[m[s[m[i].f[0]][l[m[i].f[0]] - 1]].k + 1]];
                ind = ins(m[s[m[i].f[0]][l[m[i].f[0]] - 1]].f[m[s[m[i].f[0]][l[m[i].f[0]] - 1]].k], m[s[m[i].f[0]][l[m[i].f[0]] - 1]].j);
                memmove(s[m[s[m[i].f[0]][l[m[i].f[0]] - 1]].f[m[s[m[i].f[0]][l[m[i].f[0]] - 1]].k]] + ind + 1, s[m[s[m[i].f[0]][l[m[i].f[0]] - 1]].f[m[s[m[i].f[0]][l[m[i].f[0]] - 1]].k]] + ind, (l[m[s[m[i].f[0]][l[m[i].f[0]] - 1]].f[m[s[m[i].f[0]][l[m[i].f[0]] - 1]].k]] - ind) * sizeof(int));
                s[m[s[m[i].f[0]][l[m[i].f[0]] - 1]].f[m[s[m[i].f[0]][l[m[i].f[0]] - 1]].k]][ind] = s[m[i].f[0]][l[m[i].f[0]] - 1], l[m[s[m[i].f[0]][l[m[i].f[0]] - 1]].f[m[s[m[i].f[0]][l[m[i].f[0]] - 1]].k]]++;
                l[m[i].f[0]]--;
            }
        }
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < l[i]; j++)
                ans += m[s[i][j]].v[i];
        cout << ans << '\n';
    }
}

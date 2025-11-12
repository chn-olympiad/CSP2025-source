#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N][5], ans;

struct A
{
    int x, y, z;
};

map<int, map<int, vector<A>>> m;
int s[5];
bool f[5];

struct L
{
    int x = 0, y0 = 0, y = 0, z = 0;
};

int main()
{
    freopen("club1.in", "r", stdin);
//    freopen("club.out", "w", stdout);

    map<int, int> te;
    te[-1] = 3, te[-2] = 5;
    map<int, int>::reverse_iterator it = te.rbegin();
    for(; it != te.rend(); it++)
        cout << it->second << endl;

    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            f[1] = f[2] = f[3] = false;

            // 1
            int u, v = -1, rl = 0, rrl = 0, _ans = 0;
            L r[5], rr[5];
            for(int j = 1; j <= 3; j++)
                if(a[i][j] > v) u = j, v = a[i][j];

            if(s[u] + 1 <= n / 2)
            {
                for(int j = 1; j <= 3; j++)
                {
                    if(j == u) continue;
                    m[u][a[i][j] - v].push_back({i, j, a[i][j] - v});
                }
                continue;
            }
            f[u] = true;

            //for(map<int, vector<A>>::reverse_iterator k = m[u].rbegin(); v + k->first > 0 && k != m[u].rend(); k++)
            map<int, vector<A>>::reverse_iterator k = m[u].rbegin();
            _ans = INT_MIN;
            for(vector<A>::iterator j = k->second.begin(); j != k->second.end(); j++)
            {
                int x = j->x, y = j->y, z = j->z;

                if(s[y] + 1 <= n / 2)
                {
                    if(v + z > _ans) _ans = v + z, r[1] = {x, u, y, z}, rl = 1;
                    continue;
                }

                map<int, vector<A>>::reverse_iterator kk = m[y].rbegin();
                for(vector<A>::iterator jj = kk->second.begin(); jj != kk->second.end(); jj++)
                {
                    int xx = jj->x, yy = jj->y, zz = jj->z;

                    if(s[yy] + 1 <= n / 2)
                    {
                        if(v + z + zz > _ans) _ans = v + z + zz, r[1] = {x, u, y, z}, r[2] = {xx, y, yy, zz}, rl = 2;
                        continue;
                    }
                }
            }

            // 2
            v = -1;
            for(int j = 1; j <= 3; j++)
            {
                if(f[j]) continue;
                if(a[i][j] > v) u = j, v = a[i][j];
            }
            if(s[u] + 1 <= n / 2)
            {
                for(int j = 1; j <= 3; j++)
                {
                    if(j == u || f[j]) continue;
                    m[u][a[i][j] - v].push_back({i, j, a[i][j] - v});
                }
                continue;
            }
            f[u] = true;

            map<int, vector<A>>::reverse_iterator k = m[u].rbegin();
            _ans = INT_MIN;
            for(vector<A>::iterator j = k->second.begin(); j != k->second.end(); j++)
            {
                int x = j->x, y = j->y, z = j->z;

                if(s[y] + 1 <= n / 2)
                {
                    if(v + z > _ans) _ans = v + z, r[1] = {x, u, y, z}, rl = 1;
                    continue;
                }
            }

            //3
            v = -1;
            for(int j = 1; j <= 3; j++)
            {
                if(f[j]) continue;
                if(a[i][j] > v) u = j, v = a[i][j];
            }
            if(s[u] + 1 <= n / 2)
            {
                if(v > _ans) _ans = v, r[1] = {x, u, y, z}, rl = 1;
                continue;
            }


            ans += _ans;
            for(int j = 1; j <= rl; j++)
            {
                vector<int>::iterator it = m[r[j].y0][r[j].z].find({r[j].x, r[j].y0, r[j].z});
                m[r[j].y0][r[j].z].erase(it);
                for(int k = 1; k <= 3; k++)
                {
                    if(k == r[j].y0) continue;
                    m[r[j].y][r[j].z].push_back({r[j].x, r[j].y, a[r[j].x][y] - a[r[j].x][k]})
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}

// Bye
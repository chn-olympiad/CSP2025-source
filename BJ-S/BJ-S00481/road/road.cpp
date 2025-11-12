#include <bits/stdc++.h>
#define int long long
using namespace std;

const int NR = 1e4 + 13, MR = 1e6;
int n, m, k, ans = 1e17;
int fa[NR], c[12];
bool flag[12];
struct node
{
    int val, x, y;
}w[MR + 7], a[11][NR];
vector<int> v;

int getfa(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = getfa(fa[x]);
}

bool cmp(node u, node v)
{
    return u.val <= v.val;
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
        scanf("%lld%lld%lld", &w[i].x, &w[i].y, &w[i].val);
    for(int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for(int j = 1; j <= n; j++)
        {
            scanf("%lld", &a[i][j].val);
            a[i][j].x = n + i, a[i][j].y = j;
        }
        sort(a[i] + 1, a[i] + n + 1, cmp);
    }
    sort(w + 1, w + m + 1, cmp);
    int nk = n, sum = 0, numk;
    for(int num = 0; num <= (1<<k) - 1; num++)
    {
        for(int i = 1; i <= n; i++)
            fa[i] = i;
        nk = n, sum = 0, numk = num;
        memset(flag, false, sizeof(flag));
        v.clear();
        for(int i = 1; i <= k; i++)
        {
            if((numk&1) != 0)
            {
                v.push_back(i);
                a[i][0].val = 1, nk++;
                sum += c[i];
                fa[n + i] = n + i;
            }
            numk >>= 1;
        }
        int mn, id;
        for(int i = 1; i <= m; i++)
        {
            mn = w[i].val, id = 0;
            for(int j = 0; j < v.size(); j++)
            {
                if(a[v[j]][0].val > n) continue;
                if(a[v[j]][a[v[j]][0].val].val <= mn)
                {
                    mn = a[v[j]][a[v[j]][0].val].val;
                    id = v[j];
                }
            }
            if(id == 0)
            {
                if(getfa(w[i].x) == getfa(w[i].y)) continue;
                else sum += mn, fa[fa[w[i].x]] = fa[w[i].y], nk--;
            }
            else
            {
                i--;
                if(getfa(id + n) == getfa(a[id][a[id][0].val].y))
                {
                    a[id][0].val++;
                    continue;
                }
                else sum += mn, fa[fa[id + n]] = fa[a[id][a[id][0].val].y], nk--;
                a[id][0].val++;
            }
            if(nk == 1) break;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
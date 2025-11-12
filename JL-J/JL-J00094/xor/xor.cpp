#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
typedef pair<int,int> PII;
queue<PII> q;
int n,k;
int a[N];
int st[N];
struct edge
{
    int star,ends;
    bool   operator < (const edge r)const
    {
        return star < r.star;
    }
}edges[N];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    bool flag = true;
    for (int i = 1;i <= n;i ++)
    {
        cin >> a[i];
        if (a[i] != 1)
                flag = false;
    }
    if (k == 0 && flag)
    {
        cout << n / 2 << endl;
        return 0;
    }
    int s = 0;
    for (int i = 1;i <= n;i ++)
    {
        int res = k ^ a[i];
        int sta = i;
        //cout << k << ' ' << a[i] << endl;
        //cout << res << endl;
        int j = i;
        bool is_flag = true;
       while (res > 0 && j <= n)
       {
            j ++;
            res ^= a[j];
       }
        if (res == 0 )
        {
            s ++;
            q.push({sta,j});
        }
    }
    int uu = 0;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        edges[++uu] = {t.first,t.second};
    }
    sort(edges + 1,edges + 1 + uu);
    int res = 1;
    int uend = edges[1].ends;
    for (int i = 2;i <= uu;i ++)
    {
        if (edges[i].star > uend)
        {
            res ++;
        }
        uend = max(uend,edges[i].ends);
    }
    cout << res << endl;
    return 0;
}

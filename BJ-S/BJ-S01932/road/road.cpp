#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 10005
#define MAXM 1000005
#define MAXK 15
#define int long long

struct node
{
    int u, v, w;
} s[MAXM], tm[MAXM];

bool cmp(node x, node y)
{
    return x.w < y.w;
}

int pre[MAXN];
int c[MAXK], a[MAXK][MAXN];
int n, m, k, ans = -1;

int find(int x)
{
    if(pre[x] == x)  return x;
    else return pre[x] = find(pre[x]);
}

void print(node p[], int cnt)
{
    for(int i = 1; i <= cnt; i ++)  cout << p[i].u << " " << p[i].v << " " << p[i].w << endl;
    cout << endl;
}

void mint(node p[], int cnt, int add)
{
    for(int i = 1; i <= n; i ++)  pre[i] = i;
    for(int i = 1; i <= n; i ++)  tm[i] = p[i];
    int tot = 0, sum = add;
    sort(p + 1, p + 1 + cnt, cmp);
    for(int i = 1; i <= cnt && tot <= n - 1; i ++)
    {
        int rx = find(p[i].u), ry = find(p[i].v);
        if(rx == ry)  continue;
        pre[rx] = ry, tot ++;
        //cout << p[i].u << " " << p[i].v << " " << p[i].w << endl;
        sum += p[i].w;
    }
    //cout << cnt << " " << add << " " << sum << endl;
    //cout << endl << endl;
    for(int i = 1; i <= n; i ++)  p[i] = tm[i];
    if(ans != -1)  ans = min(ans, sum);
    else  ans = sum;
}

void per(int t, node p[], int cnt, int add)
{
    if(t <= k)
    {
        for(int i = 1; i <= cnt; i ++)  tm[i] = p[i];
        //cout << "cur:" << t << " " << cnt << " " << add << endl;
        per(t + 1, p, cnt, add);
        for(int i = 1; i <= n; i ++)
            p[++ cnt] = {t, i, a[t][i]};
        per(t + 1, p, cnt, add + c[t] + a[t][t]);
        for(int i = 1; i <= cnt; i ++)  p[i] = tm[i];
        return;
    }
    if(t == k + 1)
    {
        //print(p, cnt);
        mint(p, cnt, add);
        return;
    }
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++)
        cin >> s[i].u >> s[i].v >> s[i].w;
    bool flag = true;
    for(int i = 1; i <= k; i ++)
    {
        cin >> c[i];
        if(c[i])  flag = false;
        for(int j = 1; j <= n; j ++)
        {
            cin >> a[i][j];
            if(a[i][j])  flag = false;
        }
    }
    if(flag)
    {
        cout << 0 << endl;
        return 0;
    }

    per(1, s, m, 0);
    cout << ans << endl;
    return 0;
}

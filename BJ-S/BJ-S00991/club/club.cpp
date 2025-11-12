#include<bits/stdc++.h>
using namespace std;
struct s
{
    int c, xy, id1, id2;
}a[100005];
bool cmp(s x, s y)
{
    return x.c > y.c;
}
void solve()
{
    int n, res = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x, y, xy;
        cin >> x >> y >> xy;
        if(x <= y && x <= xy)
        {
            a[i].xy = max(y, xy);
            a[i].c = fabs(y - xy);
            if(y >= xy) a[i].id1 = 2, a[i].id2 = 3;
            else a[i].id1 = 3, a[i].id2 = 2;
        }
        else if(y <= x && y <= xy)
        {
            a[i].xy = max(x, xy);
            a[i].c = fabs(x - xy);
            if(x >= xy) a[i].id1 = 1, a[i].id2 = 3;
            else a[i].id1 = 3, a[i].id2 = 1;
        }
        else
        {
            a[i].xy = max(x, y);
            a[i].c = fabs(x - y);
            if(x >= y) a[i].id1 = 1, a[i].id2 = 2;
            else a[i].id1 = 2, a[i].id2 = 1;
        }
    }
    sort(a+1, a+n+1, cmp);
    vector<int> sum(5, 0);
    for(int i = 1; i <= n; i++)
    {
        int id1 = a[i].id1, id2 = a[i].id2;
        if(sum[id1] < n/2)
        {
            sum[id1]++;
            res += a[i].xy;
        }
        else
        {
            sum[id2]++;
            res += a[i].xy - a[i].c;
        }
    }
    cout << res << endl;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

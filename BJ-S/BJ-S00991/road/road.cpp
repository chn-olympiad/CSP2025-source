#include<bits/stdc++.h>
using namespace std;
struct s
{
    int x, y, xy;
}a[100005];
bool cmp(s x, s y)
{
    return x.xy < y.xy;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y >> a[i].xy;
    for(int i = 1; i <= k; i++)
    {
        int bq;
        for(int j = 1; j <= n+1; j++) cin >> bq;
    }
    sort(a+1, a+n+1, cmp);
    set<int> s;
    s.insert(a[1].x);
    s.insert(a[1].y);
    ans += a[1].xy;
    for(int i = 2; i <= n; i++)
    {
        if(s.count(a[i].x) + s.count(a[i].y) == 1)
        {
            ans += a[i].xy;
            s.insert(a[i].x);
            s.insert(a[i].y);
        }
    }
    cout << ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define il inline
#define pi pair<int, int>
#define mkp make_pair
typedef long long ll;
const int N = 1e5 + 10;
priority_queue<pi> qq[3];
struct nn
{
    int v[3], id;
}a[N];
il bool cmp(nn n1, nn n2)
{
    return n1.v[0] > n2.v[0];
}
il bool cmp1(nn n1, nn n2)
{
    return n1.v[1] > n2.v[1];
}
il bool cmp2(nn n1, nn n2)
{
    return n1.v[2] > n2.v[2];
}

int n;
il void bg()
{
    while(qq[0].size()) qq[0].pop();
    while(qq[1].size()) qq[1].pop();
    while(qq[2].size()) qq[2].pop();
}
il int calc(int i, int j)
{
    if(j == 0) return a[i].v[1] + a[i].v[2];
    if(j == 1) return a[i].v[0] + a[i].v[2];
    return a[i].v[0] + a[i].v[1];
}
il int mx(int i)
{
    return max(a[i].v[0], max(a[i].v[1], a[i].v[2]));
}
il int mn(int i)
{
    return min(a[i].v[0], min(a[i].v[1], a[i].v[2]));
}il bool cmp3(nn n1, nn n2)
{
    return mx(n1.id) - mn(n1.id) > mx(n2.id) - mn(n2.id);
}
int ans;
il void p(int i, int j)
{
   // cout << i << "to" << j <<"\n";
}
il bool upd(int i, int tmp)
{
    if(a[i].v[0] == tmp)
    {
        if(qq[0].size() < n / 2)
        {
            qq[0].push(mkp(calc(i, 0), i));
            ans -= calc(i, 0);
            p(i, 0);
            return true;
        }
        pi cur = qq[0].top();
        int x = cur.second;
        ll nwans = ans - calc(i, 0) + cur.first - min(calc(x, 1), calc(x, 2));
        if(nwans > ans)
        {
            qq[0].pop();
            ans = nwans;
            int y = min(calc(x, 1), calc(x, 2));
            if(calc(x, 1) == y && qq[1].size() < n / 2) qq[1].push(mkp(calc(x, 1), x)), p(x, 1);
            else qq[2].push(mkp(calc(x, 2), x)), p(x, 2);
            qq[0].push(mkp(calc(i, 0), i));
            p(i, 0);
            return true;
        }
    }
    if(a[i].v[1] == tmp)
    {
        if(qq[1].size() < n / 2)
        {
            qq[1].push(mkp(calc(i, 1), i));
            ans -= calc(i, 1);
            p(i, 1);
            return true;
        }
        pi cur = qq[1].top();
        int x = cur.second;
        ll nwans = ans - calc(i, 1) + cur.first - min(calc(x, 0), calc(x, 2));
        if(nwans > ans)
        {
            qq[1].pop();
            ans = nwans;
            int y = min(calc(x, 0), calc(x, 2));
            if(calc(x, 0) == y && qq[0].size() < n / 2) qq[0].push(mkp(calc(x, 0), x)), p(x, 0);
            else qq[2].push(mkp(calc(x, 2), x)), p(x, 2);
            qq[1].push(mkp(calc(i, 1), i));
            p(i, 1);
            return true;
        }
    }
    if(a[i].v[2] == tmp)
    {
        if(qq[2].size() < n / 2)
        {
            qq[2].push(mkp(calc(i, 2), i));
            ans -= calc(i, 2);
            p(i, 2);
            return true;
        }
        pi cur = qq[2].top();
        int x = cur.second;
        ll nwans = ans - calc(i, 2) + cur.first - min(calc(x, 0), calc(x, 1));
        if(nwans > ans)
        {
            qq[2].pop();
            ans = nwans;
            int y = min(calc(x, 0), calc(x, 1));
            if(calc(x, 1) == y && qq[1].size() < n / 2) qq[1].push(mkp(calc(x, 1), x)), p(x, 1);
            else qq[0].push(mkp(calc(x, 0), x)), p(x, 0);
            qq[2].push(mkp(calc(i, 2), i));
            p(i, 2);
            return true;
        }
    }
    return false;
}
il void sub0()
{
    bg();
    ans = 0;
    for(int i = 1;i <= n;++i)
        for(int j = 0;j < 3;++j)
            ans += a[i].v[j];
    sort(a + 1, a + 1 + n, cmp3);
    for(int i = 1;i <= n;++i)
    {
        if(upd(i, mx(i))) continue;
        if(upd(i, a[i].v[0] + a[i].v[1] + a[i].v[2] - mx(i) - mn(i))) continue;
      //  upd(i, mn(i));

    }
    cout << ans << "\n";
}
il void dfs(int cur, int c1, int c2, int c3, int cnt)
{
    if(cur == n + 1)
    {
        ans = max(ans, cnt);
        return;
    }
        if(c1 < n / 2) dfs(cur + 1, c1 + 1, c2, c3, cnt + a[cur].v[0]);
        if(c2 < n / 2) dfs(cur + 1, c1, c2 + 1, c3, cnt + a[cur].v[1]);
        if(c3 < n / 2) dfs(cur + 1, c1, c2, c3 + 1, cnt + a[cur].v[2]);
}
il void sub1()
{
    sort(a + 1, a + 1 + n, cmp);
    ans = 0;
    for(int i = 1;i <= n / 2;++i) ans += a[i].v[0];
    cout << ans << "\n";
}
int ss[N];
il void sub2()
{
    sort(a + 1, a + 1 + n, cmp);
    ans = 0;
    for(int i = 1;i <= n / 2;++i) ans += a[i].v[0];
    for(int i = n / 2 + 1;i <= n;++i) ans += a[i].v[1];
    cout << ans << "\n";
    //for(int i = 1;i <= n / 2;++i)
}
il void solve()
{
    cin >> n;
    bool chka = 1, chkb = 1;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 0;j < 3;++j)
        {
            cin >> a[i].v[j];
            a[i].id = i;
        }
        chka &= (a[i].v[1] == 0 && a[i].v[2] == 0);
        chkb &= (a[i].v[2] == 0);
    }
    if(chka) sub1();
   // else if(chkb) sub2();
    else if(n <= 10)
    {
        ans = 0;
        dfs(1, 0, 0, 0, 0);
        cout << ans << "\n";
    }
    else sub0();
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c[5];
struct stu
{
    ll x1,x2,x3,maxn,minn,midn,cha;
    int maxm,minm,midm,choose;
    void read()
    {
        cin >> x1 >> x2 >> x3;
    }
    void solve()
    {
        if(x1 >= x2 && x1 >= x3)
        {
            maxm = 1;
            maxn = x1;
        }
        else if(x2 >= x1 && x2 >= x3)
        {
            maxm = 2;
            maxn = x2;
        }
        else
        {
            maxm = 3;
            maxn = x3;
        }
        if(x1 <= x2 && x1 <= x3)
        {
            minm = 1;
            minn = x1;
        }
        else if(x2 <= x1 && x2 <= x3)
        {
            minm = 2;
            minn = x2;
        }
        else
        {
            minm = 3;
            minn = x3;
        }
        midm = 6 - maxm - minm;
        midn = x1 + x2 + x3 - maxn - minn;
        cha = maxn - midn;
    }

}a[100010];
bool cmp1(stu x,stu y)
{
    if(x.cha == y.cha) return x.x1 < y.x1;
    return x.cha < y.cha;
}
bool cmp2(stu x,stu y)
{
    if(x.cha == y.cha) return x.x2 < y.x2;
    return x.cha < y.cha;
}
bool cmp3(stu x,stu y)
{
    if(x.cha == y.cha) return x.x3 < y.x3;
    return x.cha < y.cha;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        for(int i = 1; i <= 3; i++)
        {
            c[i] = 0;
        }
        ll n,ans = 0,cur = 0;
        cin >> n;
        ll m = n / 2;
        for(int i = 1; i <= n; i++)
        {
            a[i].read();
            a[i].solve();
        }
        for(int i = 1; i <= n; i++)
        {
            c[a[i].maxm]++;
            ans += a[i].maxn;
            a[i].choose = a[i].maxm;
        }
        if(c[1] > m)
        {
            cur = 0;
            sort(a + 1,a + n + 1,cmp1);
            for(int i = 1; i <= n; i++)
            {
                if(cur == c[1] - m) break;
                if(a[i].choose != 1) continue;
                ans -= a[i].maxn;
                ans += a[i].midn;
                cur++;
            }
        }
        else if(c[2] > m)
        {
            cur = 0;
            sort(a + 1,a + n + 1,cmp2);
            for(int i = 1; i <= n; i++)
            {
                if(cur == c[2] - m) break;
                if(a[i].choose != 2) continue;
                ans -= a[i].maxn;
                ans += a[i].midn;
                cur++;
            }
        }
        else if(c[3] > m)
        {
            cur = 0;
            sort(a + 1,a + n + 1,cmp3);
            for(int i = 1; i <= n; i++)
            {
                if(cur == c[3] - m) break;
                if(a[i].choose != 3) continue;
                ans -= a[i].maxn;
                ans += a[i].midn;
                cur++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

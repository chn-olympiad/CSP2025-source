#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5005;
const int MOD = 998244353;
int a[MAXN];
bool cmp(ll x,ll y)
{
    return x>y;
}
ll frac(ll x)
{
    ll res = 1;
    for (int i=1;i<=x;i++)
    {
        res *= i;
    }
    return res;
}
ll c(ll x,ll y)
{
    if (x == y) return 1;
    ll res = 1;
    for (ll i=y;i>=y-x;i--)
    {
        res *= i;
    }
    return res/frac(x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (n == 3)
    {
        sort(a+1,a+n+1,cmp);
        if (a[1]*2 < a[2]+a[3])
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
        return 0;
    }
    ll cur = 0;
    for (int i=1;i<=n;i++)
    {
        if (a[i] == 1)
        {
            cur++;
        }
    }
    ll ans = 0;
    for (int i=4;i<=cur;i++)
    {
        ans += c(i,cur)%MOD;
    }
    cout<<ans%MOD<<endl;
    return 0;
}

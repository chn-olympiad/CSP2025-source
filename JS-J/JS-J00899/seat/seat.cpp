#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,s,t) for(ll i = s;i <= t;++i)
#define per(i,t,s) for(ll i = t;i >= s;--i)
const ll N = 1e3 + 5;
ll n;
ll m;
ll k;
ll cnt;
ll row;
ll col;
ll a[N] = {};
ll ans[N][N] = {};
inline void openfile(string s)
{
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
inline void closefile()
{
    fclose(stdin);
    fclose(stdout);
}
int main()
{
    openfile("seat");
    scanf("%lld %lld",&n,&m);
    rep(i,1,n * m)
    {
        scanf("%lld",&a[i]);
        if(i == 1)
            k = a[i];
    }
    sort(a + 1,a + n * m + 1,greater <ll> ());
    rep(j,1,m)
        rep(i,1,n)
            ans[i][j] = a[++cnt];
    rep(j,1,m)
    {
        rep(i,1,n)
        {
            if(ans[i][j] == k)
            {
                col = j;
                row = i;
                if(!(col & 1))
                    row = n - row + 1;
                printf("%lld %lld",col,row);
                break;
            }
        }
    }
    closefile();
    return 0;
}

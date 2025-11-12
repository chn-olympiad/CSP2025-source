#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,s,t) for(ll i = s;i <= t;++i)
#define per(i,t,s) for(ll i = t;i >= s;--i)
const ll N = 1e6 + 5;
struct node
{
    ll l;
    ll r;
};
ll n;
ll k;
ll cnt;
ll pos;
ll ans = 1;
ll a[N] = {};
ll sum[N] = {};
node s[N];
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
inline bool cmp(node a,node b)
{
    return a.r < b.r;
}
int main()
{
    openfile("xor");
    scanf("%lld %lld",&n,&k);
    rep(i,1,n)
        scanf("%lld",&a[i]);
    rep(i,1,n)
        sum[i] = sum[i - 1] ^ a[i];
    rep(i,1,n)
    {
        ll j = i;
        while(j <= n && (sum[j] ^ sum[i - 1]) != k)
            j++;
        if(j == n + 1)
            continue;
        s[++cnt] = {i,j};
    }
    if(!cnt)
    {
        printf("0");
        return 0;
    }
    sort(s + 1,s + cnt + 1,cmp);
    pos = s[1].r;
    rep(i,1,cnt)
    {
        if(s[i].l <= pos)
            continue;
        ans++;
        pos = s[i].r;
    }
    printf("%lld",ans);
    closefile();
    return 0;
}

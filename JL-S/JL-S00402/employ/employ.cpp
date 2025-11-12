#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000;
const int mod=998244353;
int a[N];
int n,m;int cnt;
void solve()
{
    cout<<(n-m+1)*(n-m+1)/2<<'\n';
    return ;
}
void solve2()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]) ans++;
    }
    int poww=1;
    for(int i=1;i<=ans;i++)
    {
        poww=poww*i%mod;
    }
    cout<<poww<<'\n';
}
void solve3()
{
    for(int i=1;i<=n;i++) if(!a[i]) {puts("0");return ;}
    cout<<1<<'\n';
    return ;
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);

    for(int i=1;i<=n;i++)
    {
        scanf("%1lld",&a[i]);
        if(a[i]==1) cnt++;
    }
    if(cnt==n)
    {
        solve();
    }
    else if(m==1)
    {
        solve2();
    }
    else if(m==n) solve3();
}
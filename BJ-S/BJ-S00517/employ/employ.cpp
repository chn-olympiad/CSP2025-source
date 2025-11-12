#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n,c[505],sum,fs,fc,ans[505],used[505];
char s[505],f='f';
const long long mod=998244353;
#define ck cout<<f;
ll fac(ll n)
{
    ll ans=1;
    for(int i=2;i<=n;i++)
    {
        ans=ans*i%mod;
    }
    return ans%mod;
}
void check()
{
    int cnt=0,l=0;
    for(int i=1;i<=n;i++)
    {
		int p=ans[i];
        if(cnt>=c[p])
        {
            cnt++;
            continue;
        }
        if(s[i]=='0')
        {
            cnt++;
            continue;
        }
        if(s[i]=='1')
        {
            l++;
            continue;
        }
    }
    if(l>=m)sum++;
}
void dfs(int p)
{
    ck;
    if(p==n)
    {
        check();
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!used[i])
        {
            used[i]=1;
            ans[p+1]=i;
            dfs(p+1);
            used[i]=0;
        }
    }
}
void solve()
{
    dfs(0);
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    //ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]=='1')fs++;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(!c[i])fc++;
    }
    if(fs==0)
    {
        cout<<0;
        return 0;
    }
    if(fs==n)
    {
        cout<<fac(n-fc)%mod;
        return 0;
    }
    if(fc>n-m)
    {
        cout<<0;
        return 0;
    }
    if(m==n)
    {
        if(fs==n&&fc==0)
        {
            cout<<fac(n)%mod;
            return 0;
        }
        else
        {
            cout<<0;
            return 0;
        }
    }
    solve();
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

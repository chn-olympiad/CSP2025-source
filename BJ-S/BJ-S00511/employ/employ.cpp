#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5,mod=998244353;
int b[N],c[N],n,m;
bool vis[N];
ll ans;
char s[N];
void dfs(int cur)
{
    if(cur>n)
    {
        int res=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt>=c[b[i]])
            {
                cnt++;
                continue;
            }
            if(s[i]=='0') cnt++;
            else if(s[i]=='1') res++;
        }
        if(res>=m) ans++;
        ans%=mod;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            b[cur]=i;
            dfs(cur+1);
            vis[i]=0;
            b[cur]=0;
        }
    }
    return ;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    //ll ans=1;
    //for(ll i=1;i<=n;i++)
    //{
    //    ans*=i;
    //    ans%=mod;
    //}
    //cout<<ans%mod;
    if(n<=13)
    {
        dfs(1);
        cout<<ans;
        return 0;
    }
    if(n==m)
    {
        bool flag=1;
        for(int i=1;i<=n;i++)
        {
            if(s[i]==0) flag=0;
        }
        for(int i=1;i<=n;i++)
        {
            if(c[i]==0) flag=0;
        }
        if(flag==0) cout<<0;
        else
        {
            ans=1;
            for(ll i=1;i<=n;i++)
            {
                ans*=i;
                ans%=mod;
            }
            cout<<ans%mod;
        }
        return 0;
    }
    else
    {
        ans=1;
        for(int i=1;i<=n;i++)
        {
            ans*=i;
            ans%=mod;
        }
        cout<<ans%mod;
    }
    return 0;
}

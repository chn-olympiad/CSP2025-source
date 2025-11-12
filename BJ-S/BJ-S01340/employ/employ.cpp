#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[505],i,cnt,ans;
string s;
bool vis[505],f;
void dfs(int x)
{
    if(x==n+1)
    {
        if(n-cnt>=m)ans++;
        return ;
    }
    if(s[x]=='0')cnt++;
    else
    {
        if(c[x]>=cnt)cnt++;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        vis[i]=1;
        dfs(x+1);
        vis[i]=0;
    }
}
int fact(int n)
{
    int res=1;
    for(int i=1;i<=n;i++)res=(res*i)%998244353;
    return res;
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    memset(vis,0,sizeof(vis));
    cin>>n>>m>>s;
    for(i=1;i<=n;i++)cin>>c[i];
    for(i=0;i<(int)s.size();i++)
    {
        if(s[i]!='1')f=0;
    }
    s=" "+s;
    if(f)
    {
        sort(c+1,c+n+1);
        if(c[1]!=0)
        {
            cout<<fact(n);
            return 0;
        }
        for(i=2;i<=n;i++)
        {
            if(c[i]!=c[i-1]+1)
            {
                if(n-i>=m)cout<<fact(n);
                else cout<<0;
                return 0;
            }
        }
        cout<<0;
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        vis[i]=1;
        cnt=0;
        dfs(1);
        vis[i]=0;
    }
    cout<<ans;
    return 0;
}

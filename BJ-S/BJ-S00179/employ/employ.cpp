#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FILE_IO
// #define DEBUG
// debuging
const int mod=998244353;
int n,m,s[505],c[505];
int ans,p[505];
bool vis[505];
void dfs(int dep)
{
    if(dep==n+1)
    {
        int failnum=0;
        for(int i=1;i<=n;i++)
        {
            int now=p[i];
            if(failnum>=c[now]||!s[i])
                failnum++;
        }
        if(n-failnum>=m)
        {
            (++ans)%=mod;
            #ifdef DEBUG
            cout<<"Good order: ";
            for(int i=1;i<=n;i++)
                cout<<p[i]<<" ";
            cout<<endl;
            #endif // DEBUG
        }
        return;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            p[dep]=i,vis[i]=true;
            dfs(dep+1);
            vis[i]=false;
        }
}
signed main()
{
    #ifdef FILE_IO
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    #define endl '\n'
    #endif // FILE_IO
    cin>>n>>m;
    bool all1=1;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        s[i]=c-'0';
        all1&=s[i];
    }
    int cnt0=0;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]==0)
            cnt0++;
    }
    int fracn=1;
    for(int i=1;i<=n;i++)
        (fracn*=i)%=mod,cout<<"fracn*"<<i<<"to"<<fracn<<endl;
    #ifdef DEBUG
    cout<<"fracn="<<fracn<<endl;
    #endif // DEBUG
    if(all1)
    {
        if(n-cnt0>=m)
            cout<<fracn<<endl;
        else
            cout<<0<<endl;
        return 0;
    }
    if(m==n)
    {
        if(!all1||cnt0)
            cout<<0<<endl;
        else
            cout<<fracn<<endl;
        return 0;
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}

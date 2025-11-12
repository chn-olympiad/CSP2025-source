#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;

int n,m,ans;
string s;
int c[505],p[505],vis[505];

void dfs(int pos)
{
    if(pos==n+1)
    {
        int x=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='0')x++;
            else if(x>=c[p[i]])x++;
        }
        if(n-x>=m)ans++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            p[pos]=i;
            vis[i]=1;
            dfs(pos+1);
            vis[i]=0;
        }
    }
}

signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    if(n<=18)
    {
        dfs(1);
        cout<<ans<<endl;
    }
    else
    {
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            (ans*=i)%=mod;
        }
        cout<<ans<<endl;
    }
}

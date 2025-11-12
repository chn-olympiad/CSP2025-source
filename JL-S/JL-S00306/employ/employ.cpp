#include<bits/stdc++.h>
#define int long long
using namespace std;
int c[15];
int b[15];
int vis[15];
int n,m;
const int mod=998244353;
int ans=0;
string s;
void dfs(int dep)
{
    if(dep>n)
    {
        int now=0;
        int nw=0;
        for(int i=1;i<=n;i++)
        {
            if(now>=b[i])
            {
                now++;
            }
            else if(s[i-1]=='0')
            {
                now++;
            }
            else
            {
                nw++;
            }
        }
        if(nw>=m)
        {
            ans++;
            /*
            for(int i=1;i<=n;i++)
            {
                printf("%lld ",b[i]);
            }
            puts("");
            */
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            b[dep]=c[i];
            dfs(dep+1);
            vis[i]=0;
        }
    }
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&c[i]);
    }
    dfs(1);
    printf("%lld",ans%mod);
}

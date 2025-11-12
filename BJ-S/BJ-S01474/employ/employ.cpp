#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
bool a[501],f[501];
int c[501],d[501];
int ans=0,n,m;
void dfs(int step,int cnt)
{
    if(step>n)
    {
        if(n-cnt>=m)
        {
            ans++;
        }

        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i])
        {
            continue;
        }
        if(cnt>=c[i]||a[step]==0)
        {
            f[i]=1;
            d[step]=i;
            dfs(step+1,cnt+1);
            f[i]=0;
            d[step]=0;
        }
        else
        {
            d[step]=i;
            f[i]=1;
            dfs(step+1,cnt);
            f[i]=0;
            d[step]=0;
        }
    }
}
signed main()
{
    //freopen("employ.in","r",stdin);
    //freopen("employ.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        if(c=='0')a[i]=0;
        else a[i]=1;
    }

    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    if(n<=10)
        dfs(1,0);
    cout<<ans;
    return 0;
}




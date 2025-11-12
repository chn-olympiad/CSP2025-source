#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
char s[510];
int c[510];
int f[510];
int p[510];
void dfs(int now)
{
    if(now==n)
    {
        int cnt=0,su=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt>=c[p[i]] || s[i]=='0')
            {
                cnt++;
                continue;
            }
            su++;
        }
        ans+=(su>=m);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i]) continue;
        f[i]=1;
        p[now+1]=i;
        dfs(now+1);
        f[i]=0;
        p[now+1]=0;
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>(s+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    dfs(0);
    cout<<ans<<endl;
    return 0;
}
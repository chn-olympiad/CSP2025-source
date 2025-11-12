#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[505];
int c[505];
int dis[505];
bool vis[505];
long long ans=0;
const long long mod=998244353;
void dfs(int step)
{
    if(step==n+1)
    {
        int num=0;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(num>=c[dis[i]])num++;
            else
            {
                if(s[i]=='0')num++;
                else cnt++;
            }
        }
        if(cnt>=m)ans++;
        ans%=mod;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            dis[step]=i;
            dfs(step+1);
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    dfs(1);
    printf("%lld",ans);
    return 0;
}

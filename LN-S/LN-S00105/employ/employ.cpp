#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
string s;
int n,m,c[510],p[510],ans=0,k,cnt;
bool vis[510];
bool check()
{
    k=cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='0'||k>=c[p[i]])k++;
        else cnt++;
    }
    if(cnt<m)return 0;
    return 1;
}
void dfs(int dep)
{
    if(dep>n)
    {
        if(check())ans=(ans+1)%mod;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            p[dep]=i;
            dfs(dep+1);
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)cin>>c[i];
    dfs(1);
    cout<<ans;
    return 0;
}

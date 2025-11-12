#include<bits/stdc++.h>
using namespace std;
int n,m,c[20],ans,vis[20],path[20];
string s;
inline int check()
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(sum>=path[i]) sum++;
        else if(s[i]=='0') sum++;
    }
    return n-sum;
}
inline void dfs(int dep)
{
    if(dep==n+1&&check()>=m)
    {
        ans++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            path[dep]=c[i];
            dfs(dep+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++) cin>>c[i];
    dfs(1);
    cout<<ans;
    return 0;
}

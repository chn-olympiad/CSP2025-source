#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int s[1005];
int a[1005];
int vis[100];
int ans=0;

void dfs(int x,int cnt,int fail)
{
    
    vis[x]=1;
    if(s[cnt]==1&&fail<a[x])ans++;
    else fail++;
    if(cnt==n)
    {
        if(fail<=n-m)ans++;
        ans%=998244353;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)dfs(i,cnt+1,fail);
    }
    vis[x]=0;
    return;
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
    string input;
    cin>>input;
    for(int i=0;i<=n;i++)
    {
        s[i+1]=input[i]-'0';
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        vis[i]=1;
        dfs(i,1,0);
        vis[i]=0;
    }
    cout<<ans;
    return 0;
}

//gg ==1%4
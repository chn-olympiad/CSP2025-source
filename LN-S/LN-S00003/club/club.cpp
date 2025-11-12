#include <bits/stdc++.h>
using namespace std;
int a[100009][4];
int vis[4];
long long ans=0;
int t,n;
void dfs(int p,long long val)
{
    if(p==n+1)
    {
        ans=max(ans,val);
    }
    for(int i=1;i<=3;i++)
    {
        if(vis[i]+1>n/2) break;
        vis[i]++;
        dfs(p+1,val+1ll*a[p][i]);
        vis[i]--;
    }
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        vis[1]=0;
        vis[2]=0;
        vis[3]=0;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
        }
        dfs(1,0);
        cout<<ans<<endl;
    }

    return 0;
}


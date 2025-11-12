#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int t,n,a[N][4],ans=-1,vis[4];
void dfs(int x,int sum)
{
 //   cout<<x<<endl;
    if(x>n)
    {
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=3;i++)
    {
        if(vis[i]<n/2)
        {
            if(a[x][i]==0)
                continue;
            vis[i]++;
            dfs(x+1,sum+a[x][i]);
            vis[i]--;
        }
    }
}
signed main(void)
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        ans=-1;
        cin>>n;
            for(int i=1;i<=n;i++)
            {
                cin>>a[i][1]>>a[i][2]>>a[i][3];
            }
            dfs(1,0);
            cout<<ans<<endl;
    }
    return 0;
}

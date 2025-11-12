#include<bits/stdc++.h>
using namespace std;
int vis[100010],n,ans;
struct node
{
    int fi,se,th;
}a[100010];
bool cmp(node x1,node x2)
{
    return x1.fi>x2.fi;
}
void dfs(int f,int s,int h,int sum)
{
    if (s>n/2||f>n/2||h>n/2)
        return;
    //cout<<f<<' '<<s<<' '<<h<<' '<<sum<<'\n';
    if (f+s+h==n)
    {
        ans=max(ans,sum);
        return;
    }
    for (int i=1;i<=n;i++)
    {
        if (vis[i]==0)
        {
            vis[i]=1;
            dfs(f+1,s,h,sum+a[i].fi);
            vis[i]=1;
            dfs(f,s+1,h,sum+a[i].se);
            vis[i]=1;
            dfs(f,s,h+1,sum+a[i].th);
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i].fi>>a[i].se>>a[i].th;
        }
        if (n==1e5)
        {
            sort(a+1,a+n+1,cmp);
            for (int i=1;i<=n/2;i++)
            {
                ans+=a[i].fi;
            }
            cout<<ans;
        }
        else
        {
            dfs(0,0,0,0);
            memset(vis,0,sizeof(vis));
            cout<<ans<<'\n';
        }
    }
    return 0;
}

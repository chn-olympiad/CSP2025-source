#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][4],cnt,f[100005];
int ans;
int maxx(int x,int y,int z,int w)
{
    return max(x,max(y,max(z,w)));
}
void dfs(int u,int v1,int v2,int v3,int g)
{
    if(v1>n/2||v2>n/2||v3>n/2)return;
    if(u>n)
    {
        ans=max(ans,g);
        return;
    }
    dfs(u+1,v1+1,v2,v3,g+a[u][1]);
    dfs(u+1,v1,v2+1,v3,g+a[u][2]);
    dfs(u+1,v1,v2,v3+1,g+a[u][3]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        ans=0,cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            f[i]=a[i][1];
            if(a[i][2]==0&&a[i][3]==0)cnt++;
        }
        if(cnt==n)
        {
            sort(f+1,f+n+1);
            for(int i=n;i>=n/2+1;i--)
            {
                ans+=f[i];
            }
        }
        else
            dfs(1,0,0,0,0);
        cout<<ans<<'\n';
    }
    return 0;
}

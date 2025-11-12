#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000010],v[1000010],w[1000010];
int c[100],a[1000][1000010];
int ans=2147483647;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    int q=1,w=1;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        if(c[i]!=0)
        {
            q=0;
        }
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]!=0)
            {
                q=0;
                w=0;
            }
        }
        if(q==1)
        {
            cout<<0;
            return 0;
        }
        if(w==1)
        {
            ans=min(ans,c[i]);
        }
    }
    cout<<ans;
    return 0;
}

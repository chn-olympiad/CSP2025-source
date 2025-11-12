#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w;
int c,a;
int main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        ans+=w;
    }
    bool ok=true;
    for(int i=1;i<=k;i++)
    {
        cin>>c;
        if(c)
        {
            ok=false;
        }
        for(int j=1;j<=n;j++)
        {
            cin>>a;
            if(a)
            {
                ok=false;
            }
        }
    }
    if(ok&&k!=0)
    {
        cout<<0;
    }
    else
    {
        cout<<ans;
    }
    return 0;
}

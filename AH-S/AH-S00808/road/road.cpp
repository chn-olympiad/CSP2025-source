#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=99999999;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
    }
    for(int i=1;i<=k;i++)
    {
        int x,y,s=0;
        cin>>x;
        for(int j=1;j<=n;j++)
        {
            cin>>y;
            s+=y;
        }
        ans=min(ans,s);
    }
    cout<<ans;
    return 0;
}

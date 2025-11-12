#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,u,v,w,sum=0,c;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        sum+=w;
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cin>>c;
        }
    }
    cout<<sum;
    return 0;
}

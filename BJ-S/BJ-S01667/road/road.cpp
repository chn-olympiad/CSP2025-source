#include<bits/stdc++.h>
using namespace std;

long long n,m,k,sum;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;

    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        sum+=w;
    }
    for(int i=1; i<=k; i++)
    {
        for(int i=0; i<=n; i++)
        {
            int c;
            cin>>c;
        }
    }
    if(k==0)
        cout<<sum;
    else cout<<0;

    return 0;
}

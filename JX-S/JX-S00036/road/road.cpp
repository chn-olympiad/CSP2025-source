#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n,m,k;cin>>n>>m>>k;
    int sum=0,maxw=-1;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        sum+=w;
        maxw=max(maxw,w);
    }
    for(int i=0;i<k;i++)
    {
        int c;cin>>c;
        for(int j=0;j<n;j++)
        {
            int a;cin>>a;
        }
    }

    cout<<sum-maxw<<endl;
    return 0;
}


#include <iostream>
#include <cstdio>
#define ll long long

using namespace std;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    ll sum;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        sum+=w;
    }
    for(int i=0;i<k;i++)
    {
        int c;
        cin>>c;
        for(int j=0;j<n;i++)
        {
            int a;
            cin>>a;
        }
    }
    cout<<sum;
}

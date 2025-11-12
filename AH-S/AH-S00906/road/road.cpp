#include<bits/stdc++.h>
using namespace std;
struct ct
{
    int u,v,w;
};
bool lnk[1e4+1];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    ct city[m];
    int nw[10][n+1];
    for(int i=0;i<m;i++)
    {
        cin>>city[m].u>>city[m].v>>city[m].w;
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>nw[i][j];
        }
    }
    int minn=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(minn>city[m].w);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct Road
{
    int u,v;
};
vector<Road>r[1000005];
int rw[1000005];
int c[15][1005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        r[i].push_back({u,v});
        rw[i]=w;
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cin>>c[i][j];
        }
    }
    cout<<m;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

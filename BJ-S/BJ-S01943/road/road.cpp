#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.in","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int c[1e4+5][1e6+5],a[15][1e4+5];
    for(int i=1;i<+m;i++)
    {
        int x,y;
        cin>>x>>y;
        cin>>>c[x][y];
        c[y][x]=c[x][y];
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    int sum=0
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            sum+=min(c[i][j],a[i][j]);
        }
    }
    cout<<sum<<endl;
}
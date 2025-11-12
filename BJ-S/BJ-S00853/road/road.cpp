#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1020][1020],ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=z;
        a[y][x]=z;
    }
    for(int i=m+1;i<=m+k;i++)
    {
        int c;
        cin>>c;
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;
            a[i][j]=x;
            a[j][i]=x;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ans+=a[i][j];
        }
    }
    cout<<ans*2/6-1;
    return 0;
}

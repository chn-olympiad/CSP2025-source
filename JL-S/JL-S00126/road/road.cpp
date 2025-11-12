#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[100005][100005],s,c[15];
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
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];s+=c[i];
        for(int j=1;j<=n;j++)
        {
            int x;
            cin>>x;
            a[x][n+j]=z;
            a[n+j][x]=z;
        }
    }
    for(int i=1;i<=m+k;i++)
    for(int j=1;j<=m+k;j++)
    for(int d=1;d<=m+k;d++)
    {
        if(a[i][j]+a[j][k]<a[i][k])
        {
            a[i][k]=a[i][j]+a[j][k];
        }
    }
    for(int i=2;i<=n;i++)
        s+=a[1][i];
    cout<<s;
    return 0;
}

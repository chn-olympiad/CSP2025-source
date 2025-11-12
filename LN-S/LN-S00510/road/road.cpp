#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long n,m,k,f[10005][10005],a[10005],c;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        f[i][i]=0;
    memset(f,0x3f3f3f,sizeof(f));
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        f[x][y]=w;
        f[y][x]=w;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c;
        for(int j=1;j<=n;j++)
            cin>>a[j];
        for(int j=1;j<n;j++)
            for(int k=j+1;k<=n;k++)
                f[j][k]=min(f[j][k],a[j]+a[k]+c);
    }
    for(int len=2;len<=n;len++)
        for(int j=1;j+len-1<=n;j++)
        for(int k=j+1;k<=j+len-1;k++)
    {
        f[j][j+len-1]=min(f[j][k]+f[k][j+len-1],f[j][k]);
    }
    cout<<f[1][n];
    return 0;
}

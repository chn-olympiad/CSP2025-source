#include<bits/stdc++.h>
using namespace std;
long long a[10001][10001], b[100], c[11][10001];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n, m, k, id;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=-1;
            if(i==j) a[i][j]==0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        a[x][y]=a[y][x]=z;
    }
    bool flag=1;
    long long cnt=0, minn=1e9;
    for(int i=1;i<=k;i++)
    {
        cnt=0;
        cin>>b[i];
        if(b[i]!=0) flag=0;
        for(int j=1;j<=n;j++)
        {
            cin>>c[i][j];
            cnt+=c[i][j];
        }
        cnt+=b[i];
        if(cnt<minn) minn=cnt,id=i;
    }
    for(int l=1;l<=n;l++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j]<a[i][l]+a[l][j]&&a[i][j]!=-1&&a[i][l]!=-1&&a[l][j]!=-1)
                {
                    if(a[i][l]<=a[l][j]) a[l][j]=-1;
                    else a[i][l]=-1;
                }
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(a[i][j]!=-1&&i!=j) ans+=a[i][j];
        }
    }
    cout<<min(minn,ans);
    return 0;
}

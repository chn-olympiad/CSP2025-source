#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c[1001][1001],a[1001][1001],b[11],fa[1001][1001];
ll d[11],e[1001][11][1001],f[11],cf[1001][11][1001];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,sum=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y,co;
        cin>>x>>y>>co;
        c[x][y]=co;
        c[y][x]=co;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>b[i];
        for(int j=1;j<=n;j++)
        {
            cin>>d[j];
            for(int l=1;l<j;l++)
            {
                e[j][i][l]=d[j]+d[l]+b[i];
                e[l][i][j]=d[j]+d[l]+b[i];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<i;j++)
        {
            ll cnt=0,minn=INT_MAX,sb=-1;
            minn=min(minn,c[i][j]);
            for(int l=1;l<=k;l++)
            {
                if(f[l]==1) e[i][l][j]-=b[l];
                if(e[i][l][j]<minn) sb=k;
                minn=min(minn,e[i][l][j]);
            }
            if(sb==-1)
            {
                c[j][i]=0;
            }
            if(sb!=-1)
            {
                f[sb]=1;
                e[j][sb][i]=0;
            }
            cout<<minn<<endl;
            sum+=minn;
        }
    }
    cout<<sum;
    return 0;
}

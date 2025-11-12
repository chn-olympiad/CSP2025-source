#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10009;
int n,a[N][N],x,y,m,k,z,h,b[N],ans1=1e10+7;
void dfsh(int x,int y,int z)
{
    if(x==n)
    {
        ans1=min(ans1,y);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[z][i]>1000000000)
        {
            continue;
        }
        int g=a[z][i];
        a[z][i]=1000000009;
        a[i][z]=a[z][i];
        dfsh(x+1,y+g,i);
        a[z][i]=g;
        a[i][z]=g;
    }
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=1e9+7;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        a[x][y]=z;
        a[y][x]=z;
    }

    for(int i=1;i<=k;i++)
    {
        cin>>h;
        for(int j=1;j<=n;j++)
        {
            cin>>b[j];
        }
        for(int ii=1;ii<=n;ii++)
        {
            for(int j=ii+1;j<=n;j++)
            {
                if(a[ii][j]>(h+b[ii]+b[j]))
                {
                    int hh=h+b[ii]+b[j];
                    a[ii][j]=hh;
                    a[j][ii]=a[ii][j];
                }
            }
        }
    }

    dfsh(1,0,1);
    cout<<ans1<<endl;
    return 0;
}


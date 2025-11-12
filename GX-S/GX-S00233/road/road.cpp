#include<bits/stdc++.h>

using namespace std;

long long n,m,k;
long long a[10000][10000],b[10000][10000];
long long u,v,w;
long long city[10000],number[10000];
long long c,minc=1000000,flag=0,xx=0;

void way(int l,int r)
{
    for(int i=1;i<=n;i++)
    if(b[l][i]!=0&&b[i][r]!=0&&b[l][i]!=b[i][r]&&b[l][r]==0)
        b[l][r]=min(b[l][i]+b[i][r],city[l]+city[r]);
    else
        b[l][r]=min(city[l]+city[r],min(b[l][i]+b[i][r],b[l][r]));
    //cout<<b[l][r]<<" ";
}

void dfs(int l)
{
    number[l]=1;
    for(int i=1;i<=n;i++)
    {
        if(b[l][i]!=0&&number[i]==0)
        {
            xx++;
            c+=b[l][i];
            b[i][l]=0;
            if(b[i][l]!=a[i][l])
                flag=1;
            number[i]=1;
            dfs(i);
            number[i]=0;
            flag=0;
            b[i][l]=b[l][i];
            c-=b[l][i];
            xx--;
        }
    }
    if(xx==n-1)
    {
        if(flag==1)
        minc=min(c+city[0],minc);
        else
        minc=min(c,minc);
    }
    //cout<<minc<<" ";
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;

    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        a[u][v]=w;
        a[v][u]=w;
        b[u][v]=w;
        b[v][u]=w;
    }




    for(int k=1;k<=n;k++)
    {
        int c1=c;
        for(int i=0;i<=n;i++)
        {
            cin>>city[i];
        }
        for(int i=1;i<=n;i++)
        {
        for(int j=1;j<=n;j++)
        {
           way(i,j);
        }
        //cout<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            dfs(i);
        }

    }
    cout<<minc;
    return 0;
}

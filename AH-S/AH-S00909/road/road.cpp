#include<bits/stdc++.h>
using namespace std;
long long m,n,k,i,j,p,num,now;
long long u,v,w,c,cost;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    long long lu[n+11][n+11];
    for(i=0;i<=n+10;i++)
    {
        for(j=0;j<=n+10;j++) lu[i][j]=-1;
    }
    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        lu[u][v]=w;
        lu[v][u]=w;
    }

    long long a[n];

    for(i=1;i<=k;i++)
    {
        cin>>c;
        if(c==0)
        {
            for(j=1;j<=n;j++)
            {
                cin>>a[j];
                lu[n+i][j]=a[j];
                lu[j][n+i]=a[j];
            }
        }
    }
    now=1;
    num++;
    long long de[n+1+k];
    for(i=0;i<=n+k;i++)
    {
        de[i]=-1;
    }
    int city[n+1+k];
    for(i=1;i<=n+k;i++)
        city[i]=0;
    city[1]=1;
    while(num!=n+k)
    {
        for(i=1;i<=n+k;i++)
        {
            if(city[i]==0)
            {
                if((lu[now][i]!=-1)&&((lu[now][i]<de[i])||(de[i]==-1)))
                    de[i]=lu[now][i];
            }
        }
        long long zuixiao=1000000001;
        long long zuixiaon;
        for(i=1;i<=n+k;i++)
        {
            if((city[i]==0)&&(de[i]!=-1))
            {
                if(de[i]<zuixiao)
                {
                    zuixiao=de[i];
                    zuixiaon=i;
                }
            }
        }
        now=zuixiaon;
        city[now]=1;
        de[now]=-1;
        cost+=zuixiao;
        num++;

    }
    cout<<cost;
    return 0;
}










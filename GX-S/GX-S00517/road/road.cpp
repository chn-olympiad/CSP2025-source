#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road1.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k,as=0,sf=0,i,j,z,l,ma=0;
    cin>>n>>m>>k;//n城市,m道路,k乡镇数量
    long long a[m][3],c[n][n];
    for(i=0;i<m;i++)
    {
        cin>>a[i][0];//费用
        cin>>a[i][1];//连接的两座城市
        a[i][1]--;
        cin>>a[i][2];//连接的两座城市
        a[i][2]--;
    }
    long long b[k][n+1];
    for(i=0;i<k;i++)
    {
        for(j=0;j<n+1;j++)
        {
            cin>>b[i][j];//城市化改造的费用and该乡镇与原有的城市间建造道路的费用
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            long long d[k];
            for(z=0;z<k;z++)
            {
                d[z]=b[z][i+1]+b[z][j+1]+b[z][0];
            }
            sort(d,d+k);
            for(l=0;l<m;l++)
            {
                if(a[l][1]==i&&a[l][2]==j&&d[0]>=a[l][0])
                {
                    d[0]=a[l][0];
                }
            }
            if(d[0]>ma) ma=d[0];
            c[i][j]=d[0];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            as=as+c[i][j];
            sf++;
        }
    }
    if(n<=3)
    {
        if(sf>1) as=as-ma;
        cout<<as;
        return 0;
    }
    long long mi=ma;
    as=0;
    for(i=0;i<n;i++)
    {
         for(j=i+1;j<n;j++)
         {
             if(c[i][j]<mi)
             {
                 mi=c[i][j];
             }
         }
         cout<<mi<<" ";
         as=as+mi;
    }
    cout<<endl;
    cout<<as;
    return 0;
}

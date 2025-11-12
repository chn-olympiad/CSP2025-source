#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100001][5];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(long long i=1;i<=n;i++)
        {
            for(long long j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
        }
        long long m;
        m=n/2;
        long long sum[5];
        sum[1]=0;
        sum[2]=0;
        sum[3]=0;
        sum[4]=0;
        long long maxa[5];
        maxa[1]=0;
        maxa[2]=0;
        maxa[3]=0;
        long long d[10001];
        for(long long i=1;i<=n;i++)
        {
            d[i]=0;
        }
        long long p[4];
        p[1]=0;
        p[2]=0;
        p[3]=0;
        for(long long i=1;i<=n;i++)
        {
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
            {
                maxa[i]=a[i][1];
                d[i]=1;
            }
            else if(a[i][2]>a[i][1]&&a[i][2]>=a[i][3])
            {
                maxa[i]=a[i][2];
                d[i]=2;
            }
            else if(a[i][3]>a[i][1]&&a[i][3]>a[i][2])
            {
                maxa[i]=a[i][3];
                d[i]=3;
            }
        }
        for(long long i=1;i<=n;i++)
        {
            if(d[i]==1)
            {
                sum[1]=sum[1]+a[i][1];
                p[1]++;
            }
            else if(d[i]==2)
            {
                sum[2]=sum[2]+a[i][2];
                p[2]++;
            }
            else if(d[i]==3)
            {
                sum[3]=sum[3]+a[i][3];
                p[3]++;
            }
        }
        int min[4];
        min[1]=20001;
        min[2]=20001;
        min[3]=20001;
        int y[4];
        int maxb[5];
        maxb[1]=0;
        maxb[2]=0;
        maxb[3]=0;
        int s,z;
        if(p[1]>m)
        {
            for(long long i=1;i<=n;i++)
            {
                if(d[i]==1)
                {
                    for(int j=2;j<=3;j++)
                    {
                        if(a[i][j]>=maxb[1])
                        {
                            maxb[1]=a[i][j];
                            s=i;
                            z=j;
                        }
                    }
                }
            }
            sum[1]=sum[1]-a[s][1];
            sum[z]=sum[z]+a[s][z];
        }
        else if(p[2]>m)
        {
            for(long long i=1;i<=n;i++)
            {
                if(d[i]==2)
                {
                    if(a[i][1]>=maxb[2])
                    {
                        maxb[2]=a[i][1];
                        s=i;
                        z=1;
                    }
                    else if(a[i][3]>=maxb[2])
                    {
                        maxb[2]=a[i][3];
                        s=i;
                        z=3;
                    }
                }
            }
            sum[3]=sum[3]-a[s][3];
            sum[z]=sum[z]+a[s][z];
        }
        else if(p[3]>m)
        {
            for(long long i=1;i<=n;i++)
            {
                if(d[i]==3)
                {
                    for(int j=1;j<=2;j++)
                    {
                        if(a[i][j]>=maxb[3])
                        {
                            maxb[3]=a[i][j];
                            s=i;
                            z=j;
                        }
                    }
                }
            }
            sum[3]=sum[3]-a[s][3];
            sum[z]=sum[z]+a[s][z];
        }
        sum[4]=sum[1]+sum[2]+sum[3];
        cout<<sum[4]<<endl;
    }
    return 0;
}

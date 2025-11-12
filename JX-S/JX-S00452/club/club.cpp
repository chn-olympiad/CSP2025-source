#include <bits/stdc++.h>
using namespace std;
int paixu(int a,int b,int c)
{
    if(a>b)
    {
        if(a>c)
        {
            return 1;
        }
        else return 3;
    }
    else if(a>c)
    {
        if(a>b)
        {
            return 1;
        }
            else return 2;
    }
    else if(b>c)
    {
        if(b>a)
        {
            return 2;
        }
        else return 1;
    }
    else if(a<c)
    {
        if(b>c)
        {
            return 2;
        }
        else return 3;
    }
    else if(a<b)
    {
        if(b>c)
        {
            return 2;
        }
        else return 3;
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,a[100000],b[100000],c[100000],d[100000];
    int help[100000],x[100000],y[100000],z[100000];
    long long sum=0,g=1;
    cin>>t;
    for(int m=1;m<=t;m++)
    {
        cin>>n;
        sum=0;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j]>>b[j]>>c[j];
            x[j]=a[j];
            y[j]=b[j];
            z[j]=c[j];
            d[j]=paixu(a[j],b[j],c[j]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n-1;j++)
            {
                if(x[j]<x[j+1])
                {
                    swap(x[j],x[j+1]);
                }
                if(y[j]<y[j+1])
                {
                    swap(y[j],y[j+1]);
                }
                if(z[j]<z[j+1])
                {
                    swap(z[j],z[j+1]);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(d[i]==1)
            {
                help[1]++;
            }
            if(d[i]==2)
            {
                help[2]++;
            }
            if(d[i]==3)
            {
                help[3]++;
            }
        }
        if(help[1]<=n/2&&help[2]<=n/2&&help[3]<=n/2)
        {
            for(int i=1;i<=n;i++)
            {
               if(d[i]==1)
               {
                   sum+=a[i];
               }
               if(d[i]==2)
               {
                   sum+=b[i];
               }
               if(d[i]==3)
               {
                   sum+=c[i];
               }
            }
        }
        else if(b[1]==c[1]&&b[1]==0)
        {
            for(int i=1;i<=n/2;i++)
            {
                    for(int j=1;j<=n-1;j++)
                    {
                        a[g]=max(a[j],a[j+1]);
                    }
                    sum+=a[g];
                    a[g]=0;
                    g++;
            }
        }
        else if(a[1]==c[1]&&a[1]==0)
        {
            for(int i=1;i<=n/2;i++)
            {
                sum+=y[i];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,s=0,m=0;
    cin>>n;
    long long a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n-2;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            for(int l=j+1;l<=n;l++)
            {
                s=a[i]+a[j]+a[l];
                if(a[i]*2<s&&a[j]*2<s&&a[l]*2<s)
                    m++;
                s=0;
            }
        }
    }
    for(int i=1;i<=n-3;i++)
    {
        for(int j=i+1;j<=n-2;j++)
        {
            for(int l=j+1;l<=n-1;l++)
            {
                for(int t=l+1;t<=n;t++)
                {
                    s=a[i]+a[j]+a[l]+a[t];
                    if(a[i]*2<s&&a[j]*2<s&&a[l]*2<s&&a[t]*2<s)
                        m++;
                    s=0;
                }
            }
        }
    }
    for(int i=1;i<=n-4;i++)
    {
        for(int j=i+1;j<=n-3;j++)
        {
            for(int l=j+1;l<=n-2;l++)
            {
                for(int t=l+1;t<=n-1;t++)
                {
                    for(int y=t+1;y<=n;y++)
                    {
                        s=a[i]+a[j]+a[l]+a[t]+a[y];
                        if(a[i]*2<s&&a[j]*2<s&&a[l]*2<s&&a[t]*2<s&&a[y]*2<s)
                            m++;
                        s=0;
                    }
                }
            }
        }
    }
    cout<<m<<endl;
    return 0;
}

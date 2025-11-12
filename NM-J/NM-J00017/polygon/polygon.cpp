#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[100005],cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if(a[i]+a[j]>a[k])
                {
                    cnt++;
                }
            }
        }
    }
    if(n>=4)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    for(int v=k+1;v<=n;v++)
                    {
                        if(a[i]+a[j]+a[k]>a[v])
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    if(n>=5)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    for(int v=k+1;v<=n;v++)
                    {
                        for(int w=v+1;w<=n;w++)
                        {
                            if(a[i]+a[j]+a[k]+a[v]>a[w])
                            {
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
    }
    if(n>=6)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    for(int v=k+1;v<=n;v++)
                    {
                        for(int w=v+1;w<=n;w++)
                        {
                            for(int e=w+1;e<=n;e++)
                            {
                                if(a[i]+a[j]+a[k]+a[v]+a[w]>a[e])
                                {
                                    cnt++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n>=7)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    for(int v=k+1;v<=n;v++)
                    {
                        for(int w=v+1;w<=n;w++)
                        {
                            for(int e=w+1;e<=n;e++)
                            {
                                for(int h=e+1;h<=n;h++)
                                {
                                    if(a[i]+a[j]+a[k]+a[v]+a[w]>a[e])
                                    {
                                        cnt++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}

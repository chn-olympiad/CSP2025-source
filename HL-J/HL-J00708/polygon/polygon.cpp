#include<bits/stdc++.h>
using namespace std;
int n,a[5000],num;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    if(n==3)
    {
        for(int j=1;j<=n-2;j++)
        {
            for(int k=j+1;k<=n-1;k++)
            {
                for(int s=k+1;s<=n;s++)
                {
                    int sum=a[j]+a[k]+a[s];
                    int max1=max(a[j],a[k]);
                    int max2=max(max1,a[s]);
                    if(sum>max2*2)
                    {
                        num+=1;
                    }
                }
            }
        }
    }
    if(n==4)
    {
        for(int j=1;j<=n-2;j++)
        {
            for(int k=j+1;k<=n-1;k++)
            {
                for(int s=k+1;s<=n;s++)
                {
                    int sum=a[j]+a[k]+a[s];
                    int max1=max(a[j],a[k]);
                    int max2=max(max1,a[s]);
                    if(sum>max2*2)
                    {
                        num+=1;
                    }
                }
            }
        }
        for(int j=1;j<=n-2;j++)
        {
            for(int k=j+1;k<=n-1;k++)
            {
                for(int s=k+1;s<=n;s++)
                {
                    for(int i=s+1;i<=n;i++)
                    {
                        int sum=a[j]+a[k]+a[s]+a[i];
                        int max1=max(a[j],a[k]);
                        int max2=max(max1,a[s]);
                        int max3=max(max2,a[i]);
                        if(sum>max3*2)
                        {
                            num+=1;
                        }
                    }
                }
            }
        }
    }
    if(n==5)
    {
        for(int j=1;j<=n-2;j++)
        {
            for(int k=j+1;k<=n-1;k++)
            {
                for(int s=k+1;s<=n;s++)
                {
                    int sum=a[j]+a[k]+a[s];
                    int max1=max(a[j],a[k]);
                    int max2=max(max1,a[s]);
                    if(sum>max2*2)
                    {
                        num+=1;
                    }
                }
            }
        }
        for(int j=1;j<=n-2;j++)
        {
            for(int k=j+1;k<=n-1;k++)
            {
                for(int s=k+1;s<=n;s++)
                {
                    for(int i=s+1;i<=n;i++)
                    {
                        int sum=a[j]+a[k]+a[s]+a[i];
                        int max1=max(a[j],a[k]);
                        int max2=max(max1,a[s]);
                        int max3=max(max2,a[i]);
                        if(sum>max3*2)
                        {
                            num+=1;
                        }
                    }
                }
            }
        }
        for(int j=1;j<=n-4;j++)
        {
            for(int k=j+1;k<=n-3;k++)
            {
                for(int s=k+1;s<=n-2;s++)
                {
                    for(int i=s+1;i<=n-1;i++)
                    {
                        for(int r=i+1;r<=n;r++)
                        {
                            int sum=a[j]+a[k]+a[s]+a[i];
                            int max1=max(a[j],a[k]);
                            int max2=max(max1,a[s]);
                            int max3=max(max2,a[i]);
                            int max4=max(max3,a[r]);
                            if(sum>max4*2)
                            {
                                num+=1;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<num+1;
}

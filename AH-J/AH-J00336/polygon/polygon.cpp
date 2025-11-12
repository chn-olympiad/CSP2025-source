#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,s=0,a1[5001],a[5001];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a1[i];
    }
    sort(a1+1,a1+n+1);
    for(int i=n,j=1;i>=1;i--,j++)
    {
        a[j]=a1[i];
    }
    for(int i=1;i<=n-2;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if(a[i]+a[j]+a[k]>a[i]*2)
                {
                    s+=1;
                }
            }
        }
    }
    for(int i=1;i<=n-3;i++)
    {
        for(int j=i+1;j<=n-2;j++)
        {
            for(int k=j+1;k<=n-1;k++)
            {
                for(int x=k+1;x<=n;x++)
                {
                    if(a[i]+a[j]+a[k]+a[x]>a[i]*2)
                {
                    s+=1;
                }
                }
            }
        }
    }
    for(int i=1;i<=n-4;i++)
    {
        for(int j=i+1;j<=n-3;j++)
        {
            for(int k=j+1;k<=n-2;k++)
            {
                for(int x=k+1;x<=n-1;x++)
                {
                    for(int y=x+1;y<=n;y++)
                    {
                       if(a[i]+a[j]+a[k]+a[x]+a[y]>a[i]*2)
                        {
                            s+=1;
                        }
                    }
                }
            }
        }
    }
    cout<<s<<endl;
    return 0;
}

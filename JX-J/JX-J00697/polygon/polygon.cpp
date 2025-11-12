#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[10000],d;
    long long sum=0;
    long long x,ans=0,s=1;
    cin>>n;
    x=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-1;j++)
        {
            if(a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    if(n<=3)
    {
        for(int i=1;i<=n;i++)
        {
            sum=a[i]+sum;
        }
        if(sum>a[n]*2)
        {
            cout<<1;
            return 0;
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            x=n-1;
            for(int j=i;j<=n;j++)
            {
                s=j;
                sum=a[j];
                x=n-1;
                while(x>0&&sum<a[s]*2)
                {
                    s++;
                    sum=sum+a[s];
                    if(s>=3&&sum>a[s]*2)
                    {
                        ans++;
                    }
                    x--;
                }
            }
        }
        for(int i=n;i>=1;i--)
        {
            x=n-1;
            for(int j=i;j>=1;j--)
            {
                s=j;
                sum=a[j];
                x=n-1;
                while(x>0&&sum<a[s]*2)
                {
                    s--;
                    sum=sum+a[s];
                    if(s>=3&&sum>a[j]*2)
                    {
                        ans++;
                    }
                    x--;
                }
            }
        }
    cout<<ans/2;
    }
    return 0;
}

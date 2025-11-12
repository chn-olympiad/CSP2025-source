#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
int a[5001];
int b[5001];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i]+b[i-1];
    }
    if(n==3)
    {
        if(a[1]+a[2]>a[3])
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        return 0;
    }
    for(int i=3;i<=n;i++)
    {
        int x=a[i];
        int y=b[i-1];
        if(y>x)
        {
            ans++;
            ans=ans%998244353;
        }
        else
        {
            continue;
        }
        for(int j=1;j<i;j++)
        {
            y=b[i-1];
            y-=a[j];
            if(y>x)
            {
                ans++;
                ans=ans%998244353;
            }
            else
            {
                break;
            }
            for(int k=j+1;k<j;k++)
            {
                y-=a[k];
                if(y>x)
                {
                    ans++;
                    ans=ans%998244353;
                }
                else
                {
                    break;
                }
            }
        }
    }
    cout<<ans%998244353;

    return 0;
}

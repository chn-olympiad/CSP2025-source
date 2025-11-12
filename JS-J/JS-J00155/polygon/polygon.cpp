#include <bits/stdc++.h>
using namespace std;

int a[1000005];

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (n==3)
    {
        int cnt=0;
        if (a[1]+a[2]>a[3])
        {
            cnt=1;
        }
        if (a[1]+a[3]>a[2])
        {
            cnt=1;
        }
        if (a[3]+a[2]>a[1])
        {
            cnt=1;
        }
        cout<<cnt;
    }
    else
    {
        long long cnt=0,ans=0;
        for (int i=3;i<=n;i++)
        {
            cnt+=1;
            ans=1;
            for (int j=i+1;j<=n;j++)
            {
                cnt+=(2+j-i)*(j-i+1)/2+(1+j-i)*(j-i)/2+ans;
                ans=cnt;
            }
        }
        cout<<cnt;
    }
    return 0;
}

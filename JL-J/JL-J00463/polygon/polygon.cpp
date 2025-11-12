#include <bits/stdc++.h>
using namespace std;
int n,a[5010],ans=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n==3&&a[1]+a[2]>a[3])
    {
        cout<<1;
        return 0;
    }
    for(int i=3;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            long long x=0;
            x+=a[j];
            for(int k=j+1;k<=j+i-2;k++)
                x+=a[k];
            if(x>a[j+i-1])
                ans++;
        }
    }
    cout<<ans;
    return 0;
}

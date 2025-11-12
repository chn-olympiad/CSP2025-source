#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int cnt,a[100010];
    for(int i=1;i<=n;i++) cin>>a[i];
    int m=0,c=0;
    if(n==3)
    {
        for(int i=1;i<=3;i++)
        {
            m=max(m,a[i]);
            c+=a[i];
        }
        if(c>m*2)
        {
            cout<<1;
        }
    }

    if(n==4)
    {
        int i=0;
        for(int i=1;i<=4;i++)
        {
            m=max(m,a[i]);
            c+=a[i];
        }
        if(c>m*2)
        {
            i++;
        }
        m=max(a[1],max(a[2],a[3]));
        if(a[1]+a[2]+a[3]>m*2) i++;
        m=max(a[2],max(a[3],a[4]));
        if(a[4]+a[2]+a[3]>m*2) i++;
        m=max(a[4],max(a[1],a[3]));
        if(a[1]+a[4]+a[3]>m*2) i++;
        m=max(a[1],max(a[2],a[4]));
        if(a[1]+a[2]+a[4]>m*2) i++;
        cout<<i;
    }

    return 0;
}

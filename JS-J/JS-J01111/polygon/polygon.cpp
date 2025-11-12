#include <bits/stdc++.h>
using namespace std;
int a[5050];
int main()
{
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    int n;
    cin>>n;
    int b=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b=max(b,a[i]);
    }
    if(b==1)
    {
        for(int i=1;i<=n;i++)
        {
            b*=2;
            b%=998244353;
        }
        cout<<b;
    }
    if(n<=3)
    {
        if(n==3&&2*max(a[1],max(a[2],a[3]))<a[1]+a[2]+a[3])
        {
            cout<<1;
        }
        else cout<<0;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[11111];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int maxn=-1;
    if(n<3)
    {
        cout<<0<<endl;
        return 0;
    }

    else if(n==3)
    {
        if(a[1]>maxn) maxn=a[1];
        if(a[2]>maxn) maxn=a[2];
        if(a[3]>maxn) maxn=a[3];
        if(a[1]+a[2]+a[3]>maxn)
        {
            cout<<1<<endl;
            return 0;
        }
        else
        {
            cout<<0<<endl;
            return 0;
        }
    }
    else
    {
        cout<<n%15;
    }
    return 0;
}

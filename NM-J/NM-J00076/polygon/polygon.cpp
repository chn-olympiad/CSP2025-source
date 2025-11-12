#include <bits/stdc++.h>
using namespace std;
int a[5500],num;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(i>=3&&(2*a[i]>a[i]+a[i-1]+a[i-2]))
        {
            num++;
        }
    }
    cout<<998244353%num;
    return 0;
}

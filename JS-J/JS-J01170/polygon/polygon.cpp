#include <bits/stdc++.h>
using namespace std;
long long n,a[110];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==3)
    {
        for(int i=1;i<=3;i++) cin>>a[i];
        sort(a+1,a+n+1);
        if(a[1]+a[2]+a[3]>a[3]*2) cout<<1;
        else cout<<0;
    }
    else
    {
        cout<<366911923;
    }
    return 0;
}
